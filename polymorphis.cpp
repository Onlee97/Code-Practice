#include <iostream>
using namespace std;

class Base{
public:
	virtual void hi() {
		cout << "Base" << endl;
	}
};

class Child : public Base{
public:
	void hi(){
		cout << "Child" << endl;
	}
	static void print(){
		cout << "static print" << endl;
	}
};

int main(){
	// Base *object = new Base();
	// object->hi();
	Base *object;
	Child child;
	object = &child;
	object->hi();
	child.hi();

	Child::print();
}