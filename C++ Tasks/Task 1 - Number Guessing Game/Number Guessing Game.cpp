// Omar Mohammad 
// Number Guessing Game - Task I at CodSoft Intership

#include <cstdlib>
#include <iostream>
using namespace std;

// user should enter the limit of the guessing engine 
int guessNumber(int limit) {
	return rand() % limit;
}
int main() {
	string name; int limit, number, guessedNumber, newGame; bool NumberGuessed = false, flag = true, validChoice = true;
	while (flag) {
		cout << "Hello in Number Guessing Game:-\n";
		cout << "Please Enter Your Name:- "; cin >> name;
		cout << "Welcome Player " << name << '\n';
		cout << "Please Enter the limit of the random number generator:- \n";
		cin >> limit;
		number = guessNumber(limit);
		cout << "Let's Start the Game!\n";
		while (!NumberGuessed) {
			cout << "Enter Your Guess\n"; cin >> guessedNumber;
			if (guessedNumber > number) {
				cout << "Too High!\n";
			}
			else if (guessedNumber < number) {
				cout << "Too Low!\n";
			}
			else {
				NumberGuessed = true;
			}
		}
		NumberGuessed = false;
		cout << "Well Done\n";
		cout << "You Guessed the Number " << number << " Correctly\n";
		cout << "Do you want to start a new Game ?\n(1) New Game\n(2) Exit\n";
		while (validChoice) {
			cin >> newGame;
			if (newGame == 1) {
				break;
			}
			else if (newGame == 2) {
				flag = false;
				break;
			}
			else {
				cout << "Sorry Invalid Choice\n" << endl;
			}
		}	
	}
}