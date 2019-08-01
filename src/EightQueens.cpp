//============================================================================
// Name        : EightQueens.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
//Desired functionality: solves for the N queens problem, placing N number of queens on an NxN chess board
//such that no queens conflict with eachother.  Prints out the found solutions
#include <iostream>

using namespace std;
int nbs = 0;

bool check(int board[], int k)
{
	for (int i = 0; i < k; i++)
	{
		if (board[i] == board[k] || (board[i] - board[k]) == (k - i) || (board[k] - board[i]) == (k - i))
			return 0;
	}
	return 1;
}

void Queens(int nn, int board[], int k = 0)
{
	if (k == nn)
	{
		cout << endl << "Solution " << (++nbs) << ":" << endl;
		for (int i = 0; i < nn; i++)
		{
			for (int j = 0; j < nn; j++)
			{
				if (board[i] == j){
					cout << "Q ";
				}
				else{
					cout << ". ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < nn; i++)
		{
			board[k] = i;
			if (check(board, k)){
				Queens(nn, board, k + 1);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int nn = 1;
	int *board;
	while (nn > 0)
	{
		board = new int[nn];
		Queens(nn, board);
		cout << "Enter number of queens: ";
		cin >> nn;
	}
	return 0;
}

