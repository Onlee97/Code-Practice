#include <iostream>
using namespace std;


class Person{
public:
	Person(){
		cout << "Create a Person" << endl;
	}

	virtual ~Person(){
		cout << "Delete a Person" << endl;
	}
};

class Student: public Person{
public:
	Student(){
		cout << "Create a Student" << endl; 
	}


	~Student(){
		cout << "Delete a Student" << endl;
	}
};

int main(){
	Person *a = new Student();
	delete a;
	return 0;
}