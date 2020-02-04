#include<bits/stdc++.h>
using namespace std;

int countStrings(int n, string output){
	if(n == 0){
		return 1;
	}

	int len = output.length();
	char ch = output[len-1];
	int count =0;

	if(ch == '0'){
		count += countStrings(n-1, output+"0") + countStrings(n-1, output+"1");
	}

	else{
		count += countStrings(n-1, output+"0");
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int num1 = countStrings(n-1,"0");
	int num2 = countStrings(n-1,"1");

	cout<<num2+num1<<endl;

	return 0;
}