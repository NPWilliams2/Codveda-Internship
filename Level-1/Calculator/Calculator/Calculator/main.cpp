#include <iostream>
#include <limits>
#include "Calculator.h"

using namespace std;

int main() {

	double num1;
	double num2;
	char operation;
	char choice;

	cout << "===== Basic Calculator =====" << endl;

	do 
	{
		cout << "Enter first number: ";
		while (!(cin >> num1))
		{
			cout << "Invalid input. Please enter a valid number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "Enter an operator (+, -, *, /): ";
		cin >> operation;

		cout << "Enter second number: ";
		while (!(cin >> num2))
		{
			cout << "Invalid input. Please enter a valid number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (operation)
		{
		case '+':
			cout << "Result: " << add(num1, num2) << endl;
			break;

		case '-':
			cout << "Result: " << subtract(num1, num2) << endl;
			break;

		case '*':
			cout << "Result: " << multiply(num1, num2) << endl;
			break;

		case '/':
			if (num2 == 0)
			{
				cout << "Error: Division by zero is not allowed" << endl;
			}
			else
			{
				cout << "Result: " << divide(num1, num2) << endl;
			}
			break;

		default:
			cout << "Invalid operator entered" << endl;
		}

		cout << "\nWould you like to perform another calculation? (Y/N): ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	
	cout << "\n Thank you for using the calculator" << endl;

	return 0;
}