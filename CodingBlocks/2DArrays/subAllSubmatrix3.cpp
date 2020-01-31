#include<iostream>
using namespace std;

int sumAllSubmatrix3(int mat[10][10], int r, int c) {
	int sum = 0;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			// ways to choose top left
			int topLeft = (i + 1) * (j + 1);
			// ways to choose bottom right
			int bottomRight = (r - i) * (c - j);

			sum += (topLeft * bottomRight * mat[i][j]);
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int r, c;
	cin >> r >> c;
	int mat[10][10];
	int preMat[10][10];
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
	cout << sumAllSubmatrix3(mat, r, c) << endl;
	return 0;
}