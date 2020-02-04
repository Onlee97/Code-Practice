#include <iostream>
#include <string>
using namespace std;

void change_val(int& num){
	num++;
}

int main(int argc, char *argv[]){
	int num = stoi(argv[1]);
	change_val(num);
	cout << num << endl;
	return 0;
}