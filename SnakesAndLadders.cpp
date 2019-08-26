// SnakesAndLadders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "board'n'players.h"
#include <iostream>
#include <vector>

using namespace std;

class game :private BOARD {
	void round();
	void options(int i);
public:
	game() :BOARD() {}
	void play();
};

void game::play() {
	while (players.size() > 1)
		round();
	show_result();
}

void game::round() {
	cout << "Enter 'r' to roll the dice" << endl;
	cout << "Enter 'p' to view positions/score of all the players." << endl;
	cout << "Enter 's' to view all the Snakes" << endl;
	cout << "Enter 'l' to view all the Ladders" << endl;

	for (int i = 0; i < players.size(); i++) {
		cout << players[i].name << "'s turn" << endl;
		options(i);
	}
}

void game::options(int i) {
	char opt;
	do {
		cin >> opt;
		switch (opt) {
		case 'r':
		case 'R': {
			int rolled_value = dice.roll();
			cout << "You have rolled : " << rolled_value << endl;

			if (players[i].score + rolled_value > 100) {
				cout << "(Score+Rolled Value) exceeds 100.";
				cout << endl << "Therefore Rolled value is not added" << endl;
			}
			else
				players[i].score += rolled_value;

			cout << "Your new position is : " << players[i].score << endl;
			players[i].score = new_position(players[i].score);

			if (players[i].score == 100) {
				result.push_back(players[i]);
				players.erase(players.begin() + i);
			}
			return;
		}
		case 'p':
		case 'P':
			show_info();
			break;
		case 's':
		case 'S':
			display(return_Snakes());
			break;
		case 'l':
		case 'L':
			display(return_Ladders());
		default:
			cout << "Invalid Input.-_-" << endl << "Try again^-^" << endl;
		}
	} while (true);
}

int main() {
	game G1;
	G1.play();
}