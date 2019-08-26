#include "players_info.h"
#include"board_objects.h"

ostream& operator<<(ostream& ost, const PLAYER& i) {
	ost.width(11);
	ost << i.name;
	ost.width(5);
	ost << i.score;
	return ost;
}

PLAYER input(int x) {
	string name;
	int number, score;
	cout << "Enter Player " << x << "'s name";
	cin >> name;
	number = x;
	score = 0;
	return PLAYER(name, score, number);
}