#include<bits/stdc++.h>
using namespace std;
void subsequence(string input, string output) {

	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	char ch = input[0];
	string ros = input.substr(1);
	subsequence(ros, output + ch);
	subsequence(ros, output);

}

int main()
{
	string str;
	cin >> str;

	subsequence(str, "");

	return 0;
}