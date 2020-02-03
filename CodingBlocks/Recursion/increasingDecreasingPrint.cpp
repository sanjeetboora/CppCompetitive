#include<bits/stdc++.h>
using namespace std;

void decInc(int n){
	if(n==0){
		return;
	}
	cout<<n<<endl;
	decInc(n-1);
	cout<<n<<endl;
	return;
}
void incDec(int n, int i){
	if(i>n){
		return;
	}
	cout<<i<<endl;
	incDec(n, i+1);
	cout<<i<<endl;
	return;
}

int main(int argc, char const *argv[])
{	int n;
	cin >> n;
	decInc(n);
	incDec(n,1);

	return 0;

}