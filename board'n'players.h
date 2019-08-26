#pragma once

#include "players_info.h"
#include "board_objects.h"
#include "dice.h"
#include <string>
#include <vector>

using namespace std;

class BOARD {
public:
	//Constructor places snakes and ladders on board.
	BOARD() {
		snakes();
		ladders();
		init_players();
	}

protected:
	vector<object> ladder, snake;//create object snakes and ladders.
	void snakes();//initialises snakes
	void ladders();//initialises ladders
	void init_players(); //initialises players and places them on board(user input)
	//return vector snake;
	vector<object> return_Snakes() { return snake; }
	//return vector ladder;
	vector<object> return_Ladders() { return ladder; }

	DICE dice;//6 sided(default) dice

	//players - list of players who are currently playing the game (i.e rolling the dice)
	//result  - list of player who have already reached goal i.e(100th position)
	vector<PLAYER> players, result;

	//checks if current position i.e position passed as argument has any snake or ladders on it.
	//And if present the return new position else returns same position.
	int new_position(int pos);

	//shows position of all the players
	void show_info();

	//Display positions of all the snakes/ladders;
	void display(vector<object>);

	//shows result
	void show_result();
};