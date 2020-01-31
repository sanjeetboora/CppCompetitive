#include<bits/stdc++.h>
using namespace std;
void generateMatrix(int** mat, int r, int c) {
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			//mat[i][j] = (i * 10) + (j + 1);
			cin>>mat[i][j];
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
int maxSumSubmatrix(int** mat, int r, int c) {
	int maxsum = INT_MIN;
	// create suffix matrix
	// column wise sum
	for (int i = r-1; i >=0; i--)
	{
		for (int j = c-2; j >= 0 ; j--)
		{
			mat[i][j] += mat[i][j+1];
		}
	}
	// row wise sum
	for (int i = r-2; i >=0; i--)
	{
		for (int j = c-1; j >= 0 ; j--)
		{
			mat[i][j] += mat[i+1][j];
		}
	}
	// maximum sum
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			maxsum = max(maxsum, mat[i][j]);
		}
	}

	return maxsum;
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

	cout << maxSumSubmatrix(mat, r, c) << endl;

	return 0;
}