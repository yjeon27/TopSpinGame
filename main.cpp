#include "CDLL.h"
#include "TopSpin.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int size, spinSize;
	int random;

	cout << "Welcome to TopSpin! \n\nPlease enter the game size and spin size.\n\n";
	cout << "Size: ";
	cin >> size;
	cout << "SpinSize: ";
	cin >> spinSize;
	cout << endl << endl;
	TopSpin obj(size, spinSize);

	//	print table
	cout << obj;

	//	randomizing list
	cout << "How many times would you like to shuffle the deck? ";
	cin >> random;
	cout << endl << endl;

	obj.random(random);

	cout << obj;

	//	further randomize until user indicates no
	while (true) {
		string redo;
		cout << "Shuffle again (y/n)? ";
		cin >> redo;
		if (redo == "n") {
			break;
		}
		cout << "How many times would you like to shuffle the deck? ";
		cin >> random;
		cout << endl << endl;

		obj.random(random);

		cout << obj;
	}

	//	choice selection
	while (true){
		char choice;
		cout << "------------------------------------------------------------------------------------\nPlease choose from the following options:\nw. Spin\ns. Shift\nq. Quit\n\n";
		cout << "You chose to ";
		cin >> choice;
		if (choice == 's') {
			cout << " - Shift";
		}
		else if (choice == 'w') {
			cout << " - Spin";
		}
		else {
			cout << " - Quit";
		}
		cout << endl << endl;

		if (choice == 's') {
			cout << "Press anything other than 'a' or 'd' to go back to previous option!\n\n";
			while (true) {
				char dir;
				cout << "Shift to which direction? Left or right (a/d)? ";
				cin >> dir;
				cout << endl;
				if (dir == 'a') {
					obj.shiftLeft();
					cout << obj;
					if (obj.isSolved()) {
						cout << "******************************************************\n";
						cout << "CONGRATULATIONS! You rule the world! :)\n";
						cout << "******************************************************\n\n";
						break;
					}
				}
				else if (dir == 'd') {
					obj.shiftRight();
					cout << obj;
					if (obj.isSolved()) {
						cout << "******************************************************\n";
						cout << "CONGRATULATIONS! You rule the world! :)\n";
						cout << "******************************************************\n\n";
						break;
					}
				}
				else {
					break;
				}
			}
		}
		else if (choice == 'w') {
			obj.spin();
			cout << obj;

			if (obj.isSolved()) {
				cout << "******************************************************\n";
				cout << "CONGRATULATIONS! You rule the world! :)\n";
				cout << "******************************************************\n\n";
				break;
			}

		}
		else if (choice == 'q') {
			cout << "Bye for now!\n";
			break;
		}

		if (obj.isSolved()) {
			break;
		}
	}
}