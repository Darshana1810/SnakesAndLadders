#pragma once
class DICE {
	int sides;//number of sides on dice
public:
	DICE():sides(6){}//default sides 6
	DICE(int s);//user defined number of sides 
	int roll();
};