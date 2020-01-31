#include<iostream>
using namespace std;

void prefixSum(int preMat[10][10],int mat[10][10], int r, int c){
	for (int i = 0; i < c; ++i){
		preMat[0][i] = mat[0][i];
	}
	
	//columnwise
	for (int i = 1; i < r; ++i){
		for (int j = 0; j < c; ++j){
			preMat[i][j] = preMat[i-1][j] + mat[i][j];
		}
	}
	//rowwise
	for (int i = 0; i < r; ++i){
		for (int j = 1; j < c; ++j){
			preMat[i][j] += preMat[i][j-1]; 
		}
	}

	//prefixSum matrix
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; j++) {
			cout << preMat[i][j] << ", ";
		}
		cout << endl;
	}
}
int sumAllSubmatrix2(int mat[10][10],int preMat[10][10], int r, int c){
	int sum =0;
	// top left
	for (int ti = 0; ti < r; ++ti)
	{
		for (int tj = 0; tj < c; tj++) {
			// bottom right
			for (int bi = ti; bi < r; ++bi)
			{
				for (int bj = tj; bj < c; bj++) {
					
					//sum from (0,0) to (bi,bj)
					int subSum = preMat[bi][bj];

					//remove sum of (0,0) to (ti-1,bj)
					if(ti>0){
						subSum -= preMat[ti-1][bj];
					}
					//remove sum of (0,0) to (ti,bj)
					if(tj>0){
						subSum -= preMat[bi][tj-1];
					}
					//add sum of (0,0) to (ti-1,tj-1)
					if(ti >0 && tj >0){
						subSum += preMat[ti-1][tj-1];
					}

					sum += subSum;	
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
	prefixSum(preMat,mat, r, c);
	cout<<sumAllSubmatrix2(mat,preMat, r, c)<<endl;
	return 0;
}