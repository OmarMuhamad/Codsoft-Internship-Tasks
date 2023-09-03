// Omar Mohammad 
// Simple Calculator - Task II at CodSoft Intership
#include <iostream>
using namespace std;

int main() {
	cout << "Enter Two Numbers:- \n";
	int number1, number2; char ch;
	cin >> number1 >> number2;
	cout << "Enter Operation:\n1- Multiplication (*)\n2- Division (/)\n3- Addition (+)\n4- Subtraction(-)\n";
	cin >> ch;
	switch (ch) {
	case '+':
		cout << number1 << " + " << number2 << " = " << number1 + number2;
		break;
	case '-':
		cout << number1 << " - " << number2 << " = " << number1 - number2;
		break;
	case '/':
		cout << number1 << " / " << number2 << " = " << number1 / number2;
		break;
	default:
		cout << number1 << " * " << number2 << " = " << number1 * number2;
		break;
	}
	return 0;
}
