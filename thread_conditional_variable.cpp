#include <iostream>
#include <thread>
#include <mutex>
#include <stack>
#include <chrono>
#include <functional>
#include <condition_variable>

using namespace std;


std::mutex mu;
std::stack<int> myStack;
std::condition_variable cond;

void functionT1(){
	int count = 0;
	while(count < 10){
		std::unique_lock<std::mutex> locker(mu);
		myStack.push(count);
		cout << "push to stack " << count << endl; 
		locker.unlock();
		// cond.notify_one();
		cond.notify_all();
		count++;
		std::this_thread::sleep_for(chrono::seconds(1));
	}
}
void functionT2(){
	int data = 0;
	while(data != 9){
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, [](){return !myStack.empty();}); //Wait untill get notified in other thread, unlock the locker
		data = myStack.top();
		myStack.pop();
		cout << "get from stack " << data << endl;
		locker.unlock();
	}
}

int count = 0;

void functionT3(){
	for (int i = 0; i < 10 ; i++){
		std::unique_lock<std::mutex> locker(mu);
		count = i;
		cout << "Send from T3 " << i << endl;
		locker.unlock();
		cond.notify_all();
		std::this_thread::sleep_for(chrono::seconds(1));
	}
}

void functionT4(){
	int data = 0;
	while(data != 9){
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker); // Unlock the locker, wait until notified and lock again.
		cout << "Get from T4 " << count << endl;
		data = count;
		locker.unlock();
	}
}

int main(){
	std::thread t1(functionT1);
	std::thread t2(functionT2);
	t1.join();
	t2.join();
	return 0;
}