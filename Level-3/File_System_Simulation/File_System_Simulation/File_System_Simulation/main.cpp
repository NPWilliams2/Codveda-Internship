#include <iostream>
#include <limits>
#include "FileManager.h"

using namespace std;

void clearInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidChoice()
{
	int choice;

	while (true)
	{
		cout << "Enter your choice: ";

		if (cin >> choice)
		{
			clearInput();
			return choice;
		}

		cout << "Invalid input. Please enter a number" << endl;
		clearInput();
	}
}

void displayMenu()
{
	cout << "\n===== Simple File System Simulation =====" << endl;
	cout << "1. Create File" << endl;
	cout << "2. View File" << endl;
	cout << "3. Rename File" << endl;
	cout << "4. Delete File" << endl;
	cout << "5. List Files" << endl;
	cout << "6. Exit" << endl;
}

int main()
{
	FileManager fileManager;
	int choice;

	do
	{
		displayMenu();
		choice = getValidChoice();

		switch (choice)
		{
		case 1:
			fileManager.createFile();
			break;
			
		case 2:
			fileManager.viewFile();
			break;

		case 3:
			fileManager.renameFile();
			break;

		case 4:
			fileManager.deleteFile();
			break;

		case 5:
			fileManager.listFiles();
			break;

		case 6:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid choice. Please select an option from 1 to 6" << endl;
		}
	} while (choice != 6);

	return 0;
}
