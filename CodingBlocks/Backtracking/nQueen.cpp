#include<bits/stdc++.h>
using namespace std;

bool isPossible(int board[10][10], int i, int j, int n) {
	if (board[i][j] == 1) {
		return false;
	}
	//left diagonal
	int x = i, y = j;
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}
	//right diagonal
	 x = i, y = j;
	while (x >= 0 && y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}

	//column
	 x = i, y = j;
	while (x >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
	}
	return true;
}
void printboard(int board[10][10], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j] << ", ";
		}
		cout << endl;
	}
}
bool nQueen(int board[10][10], int row, int n ) {
	if (row == n) {
		printboard(board, n);
		return true;
	}

	for (int col = 0; col < n; col++)
	{
		if (isPossible(board, row, col, n)) {
			board[row][col] = 1;
			bool placeInNextRow = nQueen(board, row + 1, n);
			if (placeInNextRow == true) {
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int board[10][10]={0};
	nQueen(board, 0, 4);

	return 0;
}








