#include <iostream>
#include "board_objects.h"

ostream& operator<<(ostream& ost, const object& i) {
	ost.width(8);
	ost << i.start;
	ost.width(5);
	ost << i.end;
	return ost;
}

bool object::check(int s, int e) {
	if (s > 1 && e < 100) {
		return true;
	}
	return false;
}

object::object(int s, int e) {
	if (check(s, e))
		start = s, end = e;
}