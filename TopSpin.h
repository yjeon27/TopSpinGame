#pragma once
#include <iostream>
#include "TopSpinADT.h"
#include "CDLL.h"
using namespace std;

class TopSpin: public TopSpinADT {
private:
	int size, spinSize;
	LinkedList<unsigned int> board;

public:
	TopSpin();
	TopSpin(int, int);
	~TopSpin();

	void random(unsigned int);
	void shiftLeft();
	void shiftRight();
	void spin();
	bool isSolved();

	friend ostream& operator<< (std::ostream& os, const TopSpin& ts);

};