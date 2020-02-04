#include<iostream>
#include<ctime>
#include<set>
using namespace std;

class solution{
public:
	bool is_working(struct tm* T){
		if (T->tm_wday == 7 || T->tm_wday == 0) return false;
		if (T->tm_hour < 8) return false;
		if (T->tm_hour == 12 && (T->tm_min > 0 || T->tm_sec > 0)) return false;
		if (T->tm_hour > 17) return false;
		if (T->tm_hour == 5 && (T->tm_min > 0 || T->tm_sec > 0)) return false;
		if (T->tm_mday == 1 && T->tm_mon == 1) return false;
		if (T->tm_mday == 24 && T->tm_mon == 12) return false;
		return true;
	}

	struct tm *add_minute(struct tm* T, int minute){
		time_t sec = mktime(T);
		// time_t sec = time(0);
		time_t new_sec = sec + 60*minute;
		struct tm tNewT;;
		localtime_r(&new_sec, &tNewT);
		*T = tNewT;
		return T;
	}
};

int main(){
	struct tm time_now;
	solution S;

	time_now.tm_wday = 1;
	time_now.tm_mon = 9;
	time_now.tm_mday = 21;
	time_now.tm_year = 120;
	time_now.tm_hour = 7;
	time_now.tm_min = 50;
	time_now.tm_sec = 42;

	time_t now = time(0);
	localtime_r(&now, &time_now);
	time_now.tm_hour = 6;
	time_now.tm_wday = 0;
	cout << asctime(&time_now) << endl;
	
	cout << "Start time: " << asctime(&time_now) << endl;
	int i = 0;
	int count = 0;
	int minute = 2;
	while(i < minute){
		if (S.is_working(&time_now)){
			i++;
		}
		S.add_minute(&time_now,1);
		count++;
	}
	cout << count << endl;
	cout << "End time: " << asctime(&time_now) << endl;


	return 0;
}