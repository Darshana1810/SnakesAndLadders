#pragma once
#include<string>
#include<iostream>

using namespace std;

//stores data of player.
class PLAYER {
public:
	int score, number;
	string name;
	PLAYER(string n, int s, int no) :name(n), score(s), number(no) {}//n-name,s-score,no-number
	friend PLAYER input(int x);//x-player count
	friend ostream& operator<<(ostream& ost, const PLAYER& i);
};

PLAYER input(int x);