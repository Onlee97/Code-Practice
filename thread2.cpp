#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;


class logResource{
private:
	std::mutex mu;

public:
	void print(string msg, int i){
		std::lock_guard<std::mutex> guard(mu);
		cout << msg << " " << i << endl;
	}


};

void function1(logResource &log ,string msg){
	for (int i = 0; i < 100 ; i++){
		log.print(msg, i);
	}
}

int main(){
	logResource log;
	std::thread t1(function1,std::ref(log), "From t1");
	std::thread t2(function1,std::ref(log), "From t2");
	t1.join();
	t2.join();

	return 0;
}