#include <iostream>
#include <limits>
#include "TicTacToe.h"

using namespace std;

void clearInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidPosition()
{
	int position;

	while (true)
	{
		cout << "Choose a position from 1 to 9: ";

		if (cin >> position)
		{
			clearInput();
			
			if (position >= 1 && position <= 9)
			{
				return position;
			}

			cout << "Position must be between 1 and 9" << endl;
		}
		else
		{
			cout << "Invalid input. Please enter an valid number" << endl;
			clearInput();
		}
	}
}

char getPlayAgainChoice()
{
	char choice;

	while (true)
	{
		cout << "\nWould you like to play again? (Y/N): ";
		cin >> choice;
		clearInput();

		if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
		{
			return choice;
		}

		cout << "Invalid input. Please enter Y or N" << endl;
	}
}

int main()
{
	TicTacToe game;
	char playAgain;

	do
	{
		game.resetBoard();

		while (true)
		{
			game.displayBoard();

			cout << "\nPlayer " << game.getCurrentPlayer() << ", ";
			int position = getValidPosition();

			if (!game.makeMove(position))
			{
				cout << "Invalid move. Choose an available position between 1 and 9" << endl;
				continue;
			}

			if (game.checkWinner())
			{
				game.displayBoard();
				cout << "\nPlayer " << game.getCurrentPlayer() << " Wins!" << endl;
				break;
			}

			if (game.isBoardFull())
			{
				game.displayBoard();
				cout << "\nThe game is a draw" << endl;
				break;
			}

			game.switchPlayer();
		}

		playAgain = getPlayAgainChoice();
	} while (playAgain == 'Y' || playAgain == 'y');

	cout << "\nThank you for playing!" << endl;

	return 0;
}