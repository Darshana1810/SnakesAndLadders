// SnakesAndLadders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "board'n'players.h"
#include <iostream>
#include <vector>

using namespace std;

void turn(BOARD& board) {
	for (int i = 0; i < board.players.size(); i++) {
		char opt;
		cout << board.players[i].name << "'s turn" << endl;
		cout << "Enter 'r' to roll the dice" << endl;
		cout << "Enter 'p' to view positions/score of all the players." << endl;
		cout << "Enter 's' to view all the Snakes" << endl;
		cout << "Enter 'l' to view all the Ladders" << endl;
		do	{
			cin >> opt;	
			switch (opt) {
			case 'r': {
				int x = board.dice.roll();
				cout << "You have rolled : " << x << endl;

				if (board.players[i].score + x > 100)
					cout << "(Score+Rolled Value) exceeds 100.Therefore Rolled value is not added" << endl;
				else
					board.players[i].score += x;

				cout << "Your new position is : " << board.players[i].score << endl;
				board.players[i].score = board.new_position(board.players[i].score);

				if (board.players[i].score == 100) {
					board.result.push_back(board.players[i]);
					board.players.erase(board.players.begin() + i);
				}
				return;
			}
			case 'p':
				board.show_info();
				break;
			case 's':
				board.display(board.return_Snakes());
				break;
			case 'l':
				board.display(board.return_Ladders());
			default:
				cout << "Invalid Input.-_-" << endl << "Try again^-^" << endl;
			}
		} while (true);

	}
}

void game(BOARD& board) {
	while (board.players.size() > 1)
		turn(board);
	board.show_result();
}

int main() {
	BOARD board;
	game(board);
}