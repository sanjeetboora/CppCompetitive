#include<bits/stdc++.h>
using namespace std;
void generateMatrix(int** mat, int r, int c) {
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			mat[i][j] = (i * 10) + (j + 1);
		}
	}
}
void printMatrix(int** mat, int r, int c) {
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			cout << mat[i][j] << ", ";
		}
		cout << endl;
	}
}
void rotateMatrix1(int** mat, int r, int c) {
	// reverse all the rows
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j <= (c-1)/2; ++j)
		{
			swap(mat[i][j], mat[i][c-1-j]);
		}
	}
	// transpose of the matrix
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(i < j){
				swap(mat[i][j], mat[j][i]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int r, c;
	cin >> r >> c;
	int** mat = new int*[r];

	for (int i = 0; i < r; ++i)
	{
		mat[i] = new int [c];
	}
	generateMatrix(mat, r, c);
	printMatrix(mat, r, c);

	rotateMatrix1(mat, r, c);
	printMatrix(mat, r, c);

	return 0;
}