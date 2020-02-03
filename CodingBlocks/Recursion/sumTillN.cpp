#include<bits/stdc++.h>
using namespace std;
int sumTillN(int n){
	if(n==1){
		return n;
	}

	return n + sumTillN(n-1);

}

int main()
{	
	int n;
	cin>>n;
	int sum = sumTillN(n);
	cout<<sum<<endl;

	return 0;
}