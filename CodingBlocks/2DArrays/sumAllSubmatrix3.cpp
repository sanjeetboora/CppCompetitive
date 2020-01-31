#include<iostream>
using namespace std;
void generateMatrix(int mat[10][10], int r, int c){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			mat[i][j] = (i * 10) + (j + 1);
		}
	}
}
void printMatrix(int mat[10][10], int r, int c){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			cout << mat[i][j] << ", ";
		}
		cout << endl;
	}
}
int sumAllSubmatrix3(int mat[10][10], int r, int c) {
	int sum = 0;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			// ways to choose top left
			int topLeft = (i + 1) * (j + 1);
			// ways to choose bottom right
			int bottomRight = (r - i) * (c - j);
			//contribution of every cell
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

	generateMatrix(mat, r, c);
	printMatrix(mat, r, c);
	
	cout << sumAllSubmatrix3(mat, r, c) << endl;
	return 0;
}