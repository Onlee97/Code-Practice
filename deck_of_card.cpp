#include<iostream>
#include<string>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class card{
private:
	int type;
	int value;
public:
	card(int _type, int _value){
		type = _type;
		value = _value;
	}
	~card(){}
	void display(){
		switch(type){
			case 1:
				cout << "S";
				break;
			case 2:
				cout << "H";
				break;
			case 3:
				cout << "D";
				break;
			case 4:
				cout << "C";
				break;
		}

		switch(value){
			case 11:
				cout << "J";
				break;
			case 12:
				cout << "Q";
				break;
			case 13:
				cout << "K";
				break;
			case 1:
				cout << "A";
				break;
			default:
				cout << value;
				break;
		}
	}	
};

class deck_of_card{
private:
	stack<card*> deck;
public:	
	deck_of_card(){
		for (int i = 1; i <= 4;i++){
			for (int j = 1; j <= 13; j++){
				card *c = new card(i, j);
				deck.push(c);
			}
		}
	}

	~deck_of_card(){
		while(!deck.empty()){
			card *c = deck.top();
			cout << ", ";
			delete c;
			deck.pop();
		}
	}

	void shuffle(){
		vector<card*> buff_deck;
		while(!deck.empty()){
			card *c = deck.top();
			deck.pop();
			buff_deck.push_back(c);
		}
		random_shuffle(buff_deck.begin(), buff_deck.end());
		for (card* c : buff_deck){
			deck.push(c);
		}
	}
};

int main(){
	deck_of_card D;
	D.shuffle();
	return 0;
}