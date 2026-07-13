#pragma once

class TicTacToe
{
private:
	char board[9];
	char currentPlayer;

public:
	TicTacToe();

	void resetBoard();
	void displayBoard() const;
	bool makeMove(int position);
	bool checkWinner() const;
	bool isBoardFull() const;
	void switchPlayer();
	char getCurrentPlayer() const;
};