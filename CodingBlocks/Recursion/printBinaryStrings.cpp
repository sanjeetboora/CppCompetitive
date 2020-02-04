#include<bits/stdc++.h>
using namespace std;

void countStrings(int n, string output){
	if(n == 0){
		cout<<output<<endl;
		return;
	}

	int len = output.length();
	char ch = output[len-1];
	int count =0;

	if(ch == '0'){
		countStrings(n-1, output+"0");
		countStrings(n-1, output+"1");
	}

	else{
		countStrings(n-1, output+"0");
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	countStrings(n-1,"0");
	countStrings(n-1,"1");

	return 0;
}