// Main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TicTacToe.h"
#include <iostream>

void runX(TicTacToe& tic) {
	if (tic.getComputerType() == X) {
		cout << "Computer's turn" << endl;
		tic.computer();
	}
	else {
		int row, col;
		cout << "Eneter your position:" << endl;
		cin >> row >> col;
		tic.addX(row, col);
	}
}

void runO(TicTacToe& tic) {
	if (tic.getComputerType() == O) {
		cout << "Computer's turn" << endl;
		tic.computer();
	}
	else {
		int row, col;
		cout << "Eneter your position:" << endl;
		cin >> row >> col;		
		tic.addO(row, col);
	}
}

void print(Board board) {
	for (int row = 0; row < NROWS; row++) {
		for (int col = 0; col < NCOLS; col++) {
			if (board[row][col] == EMPTY)
				cout << "-";
			else
				cout << board[row][col];
		}
		cout << endl;
	}
}

void update(TicTacToe& tic, Board board) {
	tic.getBoard(board);
	print(board);
}

int main()
{
	cout << "Enter 'X' or 'O' for your chess type:" << endl;
	char type;
	cin >> type;
	if (type != X && type != O) return 0;
	TicTacToe tic (REVERSE_CHESS_TYPE(type));
	RESULT result = tic.getResult();
	Board board = new char*[NROWS];
	for (int i = 0; i < NROWS; i++) {
		board[i] = new char[NCOLS];
		fill(board[i], board[i] + NCOLS, EMPTY);
	}
	print(board);
	while (result == NO_RESULT) {
		runX(tic);
		update(tic, board);
		result = tic.getResult();
		if (result != NO_RESULT) break;
		runO(tic);
		update(tic, board);
		result = tic.getResult();
	}
	switch (result)
	{
	case X_WON: {
		cout << "X won !" << endl;
		break;
	}
	case O_WON: {
		cout << "O won !" << endl;
		break;
	}
	case DRAW: {
		cout << "Draw !" << endl;
		break;
	}
	default:
		break;
	}
    return 0;
}

