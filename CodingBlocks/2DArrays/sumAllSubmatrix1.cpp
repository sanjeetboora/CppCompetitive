#include<iostream>
using namespace std;
int sumAllSubmatrix1(int mat[10][10], int r, int c){
	int sum =0;
	// top left
	for (int ti = 0; ti < r; ++ti)
	{
		for (int tj = 0; tj < c; tj++) {
			// bottom right
			for (int bi = ti; bi < r; ++bi)
			{
				for (int bj = tj; bj < c; bj++) {
					//from top left to bottom right
					for (int i = ti; i <= bi; ++i)
					{
						for (int j = tj; j <= bj; ++j)
						{
							sum += mat[i][j];
						}
					}
					
				}
			}
		}
	}

	return sum;

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

	cout<<sumAllSubmatrix1(mat, r, c)<<endl;
	return 0;
}