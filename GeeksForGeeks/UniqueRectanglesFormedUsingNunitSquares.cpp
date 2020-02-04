//https://www.geeksforgeeks.org/number-unique-rectangles-formed-using-n-unit-squares/
#include<bits/stdc++.h>
using namespace std;

int uniqueRectangles(int n){
	int count=0;
	for (int length = 1; length*length <= n ; length++)
	{
		for (int height = length; height*length <= n; height++)
		{
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cout<<uniqueRectangles(n)<<endl;

	return 0;
}