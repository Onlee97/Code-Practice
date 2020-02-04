#include<iostream>
#include <string>
using namespace std;

string reverse(string s){
	int i = 0;
	int j = s.size()-1q;
	while(i < j){
		char buffer = s[i];
		s[i] = s[j];
		s[j] = buffer;
		i++;
		j--;
	}
	return s;
}

int main(int argc, char *argv[]){
	string s = "hello world";
	if (argc > 1){
		s = argv[1];
	}
	s = reverse(s);
	cout << s << endl;
	return 0;
}