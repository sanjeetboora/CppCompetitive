#include<iostream>
using namespace std;

void spiralPrint(int mat[10][10], int r, int c) {
	int startRow = 0, startCol = 0, endRow = r - 1, endCol = c - 1;
	int i = 0, j = 0;
	while (startRow <= endRow && startCol <= endCol) {
		i = startCol, j = endCol;
		//print start row
		while (i <= j) {
			cout << mat[startRow][i] << ", ";
			i++;
		}
		startRow++;

		//print end col
		i = startRow, j = endRow;
		while (i <= j) {
			cout << mat[i][endCol] << ", ";
			i++;
		}
		endCol--;

		//print end row
		if(startRow <= endRow){
			i = startCol, j = endCol;
			while (i <= j) {
				cout << mat[endRow][j] << ", ";
				j--;
			}
			endRow--;
		}

		//print start col
		if(startCol <= endCol){
			i = startRow, j = endRow;
			while (i <= j) {
				cout << mat[j][startCol] << ", ";
				j--;
			}
		}
		startCol++;
	}

}
int main(int argc, char const *argv[])
{
	int r, c;
	cin >> r >> c;
	int mat[10][10];
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			mat[i][j] = (i * 10) + (j + 1);
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			cout << mat[i][j] << ", ";
		}
		cout << endl;
	}

	spiralPrint(mat, r, c);
	return 0;
}