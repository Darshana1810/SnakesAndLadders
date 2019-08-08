#include "board'n'players.h"
#include <vector>
#include <iostream>


using namespace std;

ostream& operator<<(ostream& ost,const PLAYER& i) {
	ost.width(11);
	ost << i.name;
	ost.width(5);
	ost<< i.score;
	return ost;
}

ostream& operator<<(ostream& ost, const object& i) {
	ost.width(8);
	ost << i.start;
	ost.width(5);
	ost << i.end;
	return ost;
}

void BOARD::snakes() {
	snake.push_back(object(21, 15));
	snake.push_back(object(23, 6));
	snake.push_back(object(29, 15));
	snake.push_back(object(35, 18));
	snake.push_back(object(47, 32));
	snake.push_back(object(52, 38));
	snake.push_back(object(71, 34));
	snake.push_back(object(77, 84));
	snake.push_back(object(82, 59));
	snake.push_back(object(99, 79));
}

void BOARD::ladders() {
	ladder.push_back(object(2, 18));
	ladder.push_back(object(11, 31));
	ladder.push_back(object(12, 28));
	ladder.push_back(object(22, 40));
	ladder.push_back(object(36, 63));
	ladder.push_back(object(41, 59));
	ladder.push_back(object(46, 55));
	ladder.push_back(object(70, 94));
	ladder.push_back(object(76, 84));
	ladder.push_back(object(85, 97));
}

int BOARD::new_position(int pos) {
	for (object i : snake)
		if (pos == i.start) {
			pos = i.end;
			cout << "Snake found at " << i.start << endl;
			cout << "New position " << i.end << endl;
		}
	cout << "Snake not present at " << pos << endl;
	for (object i : ladder)
		if (pos == i.start) {
			pos = i.end;
			cout << "Ladder found at " << i.start << endl;
			cout << "New position " << i.end << endl;
		}
	cout << "Ladder not Present at " << pos << endl;
	return pos;
}

void BOARD::init_players(){
	int number;
	cout << "Enter Number of players(2-8): ";
	cin >> number;
	for (int i = 0; i < number; i++) {
		string name;
		cout << "Enter Player " << i + 1 << "'s name";
		cin >> name;
		players.push_back(PLAYER(name, 0, i + 1));
	}
}

void BOARD::show_result() {
	int pos = 1;
	cout << "---RESULT---" << endl;
	for (PLAYER& i : result) {
		cout << "Position : " << pos++ << endl << "Name : " << i.name;
	}
}

void BOARD::display(vector<object> T) {
	cout << " Start | End" << endl;
	for (object& i : T) {
		cout << i << endl;
	}
}

void BOARD::show_info() {
	cout << "   Name   | Score" << endl;
	for (PLAYER& i : players) {
		cout << i << endl;
	}
}