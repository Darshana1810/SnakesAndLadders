#include "dice.h"
#include <ctime>
#include <iostream>

using namespace std;

int DICE::roll() {
	srand((unsigned)time(0));
	int rolled = rand() % sides + 1;
	return rolled;
};

DICE::DICE(int s) {
	if (s >= 1) {
		if (s == 1)	throw 1011;
		if (s > 25) throw 1012;
		sides = s;
		cout << sides << " Sided dice has bee created";
	}
	else
		throw 1021;//number of sides either 0 or less then 0.
}