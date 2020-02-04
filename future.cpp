#include <future>
#include <string>
#include <thread>
#include <iostream>

using namespace std;

int functionT1(std::future<int> &f){
	int N = f.get();

	int result = N*100;
	cout << "Result is " << result << endl;
	return result;
}

int functionT2(std::shared_future<int> f){
	int N = f.get();

	int result = N*100;
	cout << "Result is " << result << endl;
	return result;
}



int main(){
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::shared_future<int> sf = f.share();

	std::future<int> fu = std::async(std::launch::async, functionT1, std::ref(f));
	std::future<int> fu2 = std::async(std::launch::async, functionT2, sf);
	std::future<int> fu3 = std::async(std::launch::async, functionT2, sf);
	std::future<int> fu4 = std::async(std::launch::async, functionT2, sf);
	
	p.set_value(5);
	// int result = fu2.get();
	// cout << "From Main " << result << endl;
	return 0;
}