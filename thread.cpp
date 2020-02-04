#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <future>
using namespace std;

class LogFile {
private:
	std::mutex m_mutex;
	ofstream f;
public:
	LogFile(){
		f.open("log.txt");
	}
	void shared_print(string msg, int value){
		std::lock_guard<mutex> locker(m_mutex);
		// The lock stop other thread from accessing the recourse
		// After the function terminated, the lock guard also go destructed
		// Freeing the resouce
		cout << "From " << msg << ": " << value << endl;
	}
};

int function1(LogFile &log){
	for (int i = 0; i < 100; i++){
		log.shared_print("t1", i);
	}
}

int main(){
	LogFile log;
	std::thread t1(function1(log));

	for (int i = 0 ; i > -100; i--){
		log.shared_print("main", i);
	}	
	t1.join();
	return 0;
}