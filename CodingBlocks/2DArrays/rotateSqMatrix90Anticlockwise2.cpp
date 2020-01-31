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
void rotateMatrix2(int** mat, int N) {
	// consider all levels
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = i; j < N - i - 1; ++j)
		{
			//current cell in temp
			int temp = mat[i][j];

			//move right to top
			mat[i][j] = mat[j][N-1-i];

			//move bottom to right
			mat[j][N-1-i] = mat[N-1-i][N-1-j];

			//move left to bottom
			mat[N-1-i][N-1-j] = mat[N-1-j][i];

			//temp to left
			mat[N-1-j][i] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int** mat = new int*[N];

	for (int i = 0; i < N; ++i)
	{
		mat[i] = new int [N];
	}
	generateMatrix(mat, N, N);
	printMatrix(mat, N, N);

	rotateMatrix2(mat, N);
	printMatrix(mat, N, N);

	return 0;
}