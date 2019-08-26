#pragma once
#include <iostream>

using namespace std;

//object-->Snakes and Ladders
class object {
public:
	int start, end;
	object(int s, int e);
	bool check(int s, int e);
	friend ostream& operator<<(ostream& ost, const object& i);
};
