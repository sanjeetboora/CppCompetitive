//https://leetcode.com/discuss/interview-question/370112

#include <bits/stdc++.h>
using namespace std;


set<string> uniqueSubstrings(string str, int k) {

	int len = str.length();
	set<string> res;
	for (int i = 0; i < len; i++)
	{
		int arr[26] = {0};
		int j = i;
		for (; j < i + k ; j++)
		{
			if (arr[str[j] - 'a'] == 0) {
				arr[str[j] - 'a']++ ;
			} else {
				break;
			}
		}
		if (j == i + k and res.find(str.substr(i, k)) == res.end()) {
			res.insert(str.substr(i, k));

		}
	}
	return res;
}

int main(int argc, char const *argv[])
{

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	int k;
	cin >> str >> k;

	set<string> res = uniqueSubstrings(str, k);
	for (string x : res)
	{
		cout << x << ", ";
	} cout << endl;

	return 0;
}


/*
Input: s = "abcabc", k = 3
Output: ["abc", "bca", "cab"]


Input: s = "abacab", k = 3
Output: ["bac", "cab"]

Input: s = "awaglknagawunagwkwagl", k = 4
Output: ["wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag"]

*/



