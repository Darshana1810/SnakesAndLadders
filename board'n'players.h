#pragma once

#include <string>
#include <vector>

using namespace std;

//object-->Snakes and Ladders
class object {
public:
	int start, end;
	friend void display(vector<object>&);
	object(int s, int e) :start(s), end(e) {}
};

class DICE {
public:
	static int sides;//max value on dice. Default 6.
	int roll();
};

class PLAYER {
public:
	int score, number;
	string name;
	PLAYER(string n, int s, int no) :name(n), score(s), number(no) {}
};

class BOARD {
	vector<object> ladder, snake;
	void snakes();//initialises snakes
	void ladders();//initialises ladders
	void init_players(); //initialises players and places them on board(user input)

public:
	//return vector snake;
	vector<object> Snakes() { return snake; }
	//return vector ladder;
	vector<object> Ladders() { return ladder; }


	DICE dice;//6 sided(default) dice

	//players - list of players who are currently playing the game (i.e rolling the dice)
	//result  - list of player who have already reached goal i.e(100th position)
	vector<PLAYER> players, result; 
	
	//Constructor places snakes and ladders on board.
	BOARD() { 
		snakes();
		ladders();	
		init_players();
	}

	//checks if current position i.e position passed as argument has any snake or ladders on it.
	//And if present the return new position else returns same position.
	int new_position(int pos);
	
	//shows position of all the players
	void show_info();

	//Display positions of all the snakes/ladders;
	void display(vector<object>&);

	//shows result 
	void show_result();
};