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
bool search(int** mat, int r, int c, int key) {
	int i = 0, j = c - 1;

	while (i < r && j >= 0) {
		if (key == mat[i][j]) {
			return true;
		}
		else if (key < mat[i][j]) {
			j--;
		}
		else {
			i++;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int r, c, key;
	cin >> r >> c >> key;
	int** mat = new int*[r];

	for (int i = 0; i < r; ++i)
	{
		mat[i] = new int [c];
	}
	generateMatrix(mat, r, c);
	printMatrix(mat, r, c);

	if (search(mat, r, c, key)) {
		cout << key << " found" << endl;
	}
	else {
		cout << key << " not found" << endl;
	}

	return 0;
}