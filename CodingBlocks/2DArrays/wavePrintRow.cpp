#include<iostream>
using namespace std;
void wavePrintRow(int mat[10][10], int r, int c){
	for (int i = 0; i < r; ++i)
	{
		if(i&1){
			for (int j = c-1; j >= 0; j--)
			{
				cout<<mat[i][j]<<", ";
			}
		}
		else{
			for (int j = 0; j < c; j++)
			{
				cout<<mat[i][j]<<", ";
			}
		}
		cout<<endl;
	}


}
int main(int argc, char const *argv[])
{
	int r,c;
	cin>>r>>c;
	int mat[10][10];
	for (int i = 0; i < r; ++i)
	{	
		for (int j = 0; j < c; j++){
			mat[i][j] = (i*10)+ (j+1);
		}
	}

	for (int i = 0; i < r; ++i)
	{	
		for (int j = 0; j < c; j++){
			cout<<mat[i][j]<<", ";
		}
		cout<<endl;
	}
	 
	wavePrintRow(mat, r, c);
	return 0;
}