#include <bits/stdc++.h>
using namespace std;

int longestCommonSubseqRec(string str1, string str2, int i, int j) {

}

int longestCommonSubseqBottomUp(string str1, string str2) {

	int s1 = str1.length();
	int s2 = str2.length();
	int **dp = new int[s1 + 1];
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
		return dp[s1][s2];
	}



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
	cout << longestCommonSubseq(str1, str2) << endl;

	return 0;
}


// input

// output


