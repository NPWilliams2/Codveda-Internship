#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
{
	resetBoard();
}

void TicTacToe::resetBoard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = '1' + i;
	}

	currentPlayer = 'X';
}

void TicTacToe::displayBoard() const
{
	cout << "\n===== TIC-TAC-TOE =====\n" << endl;

	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool TicTacToe::makeMove(int position)
{
	int index = position - 1;

	if (position < 1 || position > 9)
	{
		return false;
	}

	if (board[index] == 'X' || board[index] == 'O')
	{
		return false;
	}

	board[index] = currentPlayer;
	return true;
}

bool TicTacToe::checkWinner() const
{
	const int winningCombination[8][3] =
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};

	for (int i = 0; i < 8; i++)
	{
		int first = winningCombination[i][0];
		int second = winningCombination[i][1];
		int third = winningCombination[i][2];

		if (board[first] == board[second] && board[second] == board[third])
		{
			return true;
		}
	}

	return false;
}

bool TicTacToe::isBoardFull() const
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 'X' && board[i] != 'O')
		{
			return false;
		}
	}

	return true;
}

void TicTacToe::switchPlayer()
{
	if (currentPlayer == 'X')
	{
		currentPlayer = 'O';
	}
	else
	{
		currentPlayer = 'X';
	}
}

char TicTacToe::getCurrentPlayer() const
{
	return currentPlayer;
}