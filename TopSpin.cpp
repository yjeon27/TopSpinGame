#include "TopSpin.h"
#include "CDLL.h"
#include <ctime>
#include <iostream>
using namespace std;

//	DONE - default constructor
TopSpin::TopSpin(){
	size = 20;
	spinSize = 4;
}

//	DONE - overloaded constructor that takes in parameters to create TopSpin game
TopSpin::TopSpin(int size, int spinSize) {
	//	default values if spinSize is set to be greater than the size of the game
	if (spinSize > size) {
		cout << "INVALID ENTRY!\nSize has been defaulted to 20\nSpinSize has been defaulted to 4.\n\n";
		cout << "Size = 20\nSpinSize = 4\n\n";
		this->size = 20;
		this->spinSize = 4;
	}
	//	if spinSize is within bounds of the size that have been inputted, pass input parameters to its local objects
	else {
		this->size = size;
		this->spinSize = spinSize;
	}
	
	//	creating a board with numbers placed chronologically in order
	for (int k = 1; k <= this->size; k++) {
		board.addData(k);
	}
}

//	DONE - overloaded operator << to print board
ostream & operator<<(ostream & os, const TopSpin & ts){
	//	takes care of the elements within the scope spinner boundary(spinSize)
	for (int i(1); i <= ts.spinSize; i++) {
		if (i == 1) {
			cout << "|" << ts.board.getData(i) << " ";
		}
		else if (i == ts.spinSize) {
			cout << ts.board.getData(i) << "| ";
		}
		else {
			cout << ts.board.getData(i) << " ";
		}
	}
	//	takes care of elements outside the spinner boundary(Size - spinSize)
	for (int i(ts.spinSize + 1); i <= ts.size; i++) {
		cout << ts.board.getData(i) << " ";
	}
	cout << endl;
	return os;
}


//	DONE - shifts elements to the left random number of times (1-19) followed by a spin
void TopSpin::random(unsigned int times){
	//	assigning a non-pseudo random number to integer k that will range from 1-19
	srand(time(NULL));
	int k = rand() % 19 + 1;

	//	for each "time", elements gets shifted left random number of times followed by a spin
	for (int a(0); a < times; a++) {
		for (int j(0); j < k; j++) {
			shiftLeft();
		}
		spin();
	}

}

//	DONE
void TopSpin::shiftLeft(){
	board.incrementHead();
}

//	DONE
void TopSpin::shiftRight(){
	board.decrementHead();
}

//	DONE
void TopSpin::spin(){
	int compare = spinSize/2;
	for (int k(1); k <= compare; k++) {
		board.swap(k, spinSize+1-k);
	}
}

//	DONE - check to see if board elements have been arranged correctly
///	return true if solved, false otherwise
///	list MUST be arranged from least to greatest (1 to size)
bool TopSpin::isSolved() {
	int count(1);
	for (int i(1); i <= size; i++) {
		if (this->board.getData(i) != i) {
			return false;
		}
	}
	return true;
}


//	DESTRUCTOR
TopSpin::~TopSpin() {
	cout << "Ending game. See you next time!\n\n";
}