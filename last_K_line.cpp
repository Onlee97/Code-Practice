#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	int K = 2;
	string filename = "input.txt";
	if (argc > 1){
		K = stoi(argv[2]);
		filename = argv[1];
	}
	ifstream file (filename);
	string L[K];
	int num_line = 0;
	while(file.peek() != EOF){
		getline(file, L[num_line % K]);
		num_line++;
	}
	for (string s : L){
		cout << s << endl;
	}
	return 0;
}