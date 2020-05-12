#include <bits/stdc++.h>
using namespace std;

int longestCommonSubseqRec(string str1, string str2, int i, int j) {

	if (i == str1.length() or j == str2.length()) {
		return 0;
	}

	if (str1[i] == str2[j]) {
		return 1 + longestCommonSubseqRec(str1, str2, i + 1, j + 1);
	}
	else {
		return max(longestCommonSubseqRec(str1, str2, i, j + 1), longestCommonSubseqRec(str1, str2, i + 1, j));
	}
}


int longestCommonSubseqTopDownDp(string str1, string str2, int i, int j, int dp[100][100]) {

	if (i == str1.length() or j == str2.length()) {
		return 0;
	}

	if (dp[i][j]) {
		return dp[i][j];
	}
	int ans = 0;

	if (str1[i] == str2[j]) {
		ans = 1 + longestCommonSubseqTopDownDp(str1, str2, i + 1, j + 1, dp);
	}
	else {
		ans = max(longestCommonSubseqTopDownDp(str1, str2, i, j + 1, dp), longestCommonSubseqTopDownDp(str1, str2, i + 1, j, dp));
	}
	dp[i][j] = ans;
	return dp[i][j];
}

int longestCommonSubseqBottomUp(string str1, string str2) {

	int s1 = str1.length();
	int s2 = str2.length();
	int **dp = new int*[s1 + 1];
	for (int i = 0; i <= s1; ++i)
	{
		dp[i] = new int[s2 + 1];
	}
	for (int i = 0; i <= s1; ++i)
	{
		for (int j = 0; j <= s2; ++j)
		{
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}

	}

	return dp[s1][s2];
}



int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str1, str2;
	cin >> str1 >> str2;

	cout << longestCommonSubseqRec(str1, str2, 0, 0) << endl;
	int dp[100][100] = {0};
	cout << longestCommonSubseqTopDownDp(str1, str2, 0, 0, dp) << endl;
	cout << longestCommonSubseqBottomUp(str1, str2) << endl;

	return 0;
}


// input
// aslkbcd
// acdsnslkkfk

// output
// 4


