#include<bits/stdc++.h>
using namespace std;

int noOfWays(int n){
	if(n <= 2){
		return n;
	}

	int result = noOfWays(n-1) + ((n-1)*noOfWays(n-2));
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cout<<noOfWays(n)<<endl;

	return 0;
}