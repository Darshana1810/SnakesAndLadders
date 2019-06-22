// SnakesAndLadders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class object {
public:
	int start, end;
	object(int s, int e) :start(s), end(e) {}
};

class DICE {
public:
	int roll();
}dice;

int DICE::roll() {
	srand((unsigned)time(0));
	int rolled = rand() % 6 + 1;
	return rolled;
}

class BOARD {
	vector<object> ladder, snake;
	void snakes();
	void ladders();
public:
	BOARD() { snakes(); ladders(); }
	int new_position(int pos);
}board;

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
			cout << "Snake found at " << i.start;
			cout << endl << "New position " << i.end;
		}
	for (object i : ladder)
		if (pos == i.start) {
			pos = i.end;
			cout << "Ladder found at " << i.start;
			cout << endl << "New position " << i.end;
		}
	return pos;
}

class PLAYER {
public:
	int score,number;
	string name;
	PLAYER(string n,int s,int no):name(n),score(s),number(no){}
};

vector<PLAYER> player_list,result;

void input() {
	int number;
	cout << "Enter Number of Players(2-8): ";
	cin >> number;
	for (int i = 0; i < number; i++) {
		string name;
		cout << "Enter Player " << i + 1 << " name";
		cin >> name;
		player_list.push_back(PLAYER(name,0,i+1));
	}
}

void turn() {
	for (PLAYER &p : player_list) {
		char c;
		cout << p.name << "'s turn"<<endl<<"Enter 'r' to roll the dice : ";
		do	 cin >> c;	while (c != 'r');
		int x= dice.roll();
		cout << "You have rolled : " << x;
		if (p.score + x > 100)
			cout << "(Score+Rolled Value) exceeds 100.Therefore Rolled value is not added";
		else
			p.score += x;
		cout << "Your new position is : " << p.score;
		p.score = board.new_position(p.score);
		if(p.score==100){
			result.push_back(p);
			player_list.erase(player_list.begin() + p.number - 1);	//p.number is 'players' index value in vector + 1;
		}
	}
}


int main() {
	input();
	turn();
	for(PLAYER i:player_list )
	cout << i.score;
}