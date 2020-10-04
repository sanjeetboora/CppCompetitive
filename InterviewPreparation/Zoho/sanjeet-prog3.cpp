#include <bits/stdc++.h>
using namespace std;

void minMaxFreq(string s) {
	unordered_map<char, int> mp;

	for (char ch : s) {
		mp[ch]++;
	}

	int mini = INT_MAX, maximum = INT_MIN;

	for (auto x : mp) {
		mini = min(mini, x.second);
		maximum = max(maximum, x.second);
	}
	vector<char> mins;
	vector<char> maxs;
	for (auto x : mp) {
		if (x.second == mini) {
			mins.push_back(x.first);
		}
		if (x.second == maximum) {
			maxs.push_back(x.first);
		}
	}

	cout << "Min Freq Char  = ";
	for (char ch : mins) {
		cout << ch << ", ";
	}
	cout << "Freq = " << mini << endl;

	cout << "Max Freq Char  = ";
	for (char ch : maxs) {
		cout << ch << ", ";
	}
	cout << "Freq = " << maximum << endl;
}

int main(int argc, char const *argv[])
{

	string str;
	cin >> str;

	minMaxFreq(str);

	return 0;
}