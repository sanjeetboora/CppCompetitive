#include<bits/stdc++.h>
using namespace std;

string keypad[10] = {"+.,","abc", "def","ghi","jkl","mno","pqrs","tuv","wxy","z"};

void printKeypad(string input, string output){
	if(input.length() == 0){
		cout<<output<<endl;
	}

	char ch = input[0];
	string ros ="";
	if(input.length() >= 2){
		ros = input.substr(1);
	}
	string keyString = keypad[ch - '0'];
	for (int i = 0; i < keyString.length(); ++i)
	{
		printKeypad(ros,output+keyString[i]);
	}
}


int main(int argc, char const *argv[])
{
	string num;
	cin>>num>>endl;
	printKeypad(num, "");

	return 0;
}