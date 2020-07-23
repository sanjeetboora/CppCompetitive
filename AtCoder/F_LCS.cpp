#include<iostream>
using namespace std;
int dp[3005][3005];
string getLCS(string str1, string str2, int len) {
	string ans = "";
	int i = str1.length(), j = str2.length();
	while (len > 0) {
		if (str1[i - 1] == str2[j - 1]) {
			ans.push_back(str1[i - 1]);
			i--;
			j--;
			len--;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j]) j--;
			else i--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int lcs(string str1, string str2) {
	int s1 = str1.length();
	int s2 = str2.length();
	for (int i = 0; i <= max(s1, s2); i++) {
		if (i <= s1 )dp[i][0] = 0;
		if (i <= s2 )dp[0][i] = 0;
	}
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[s1][s2];
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int len = lcs(str1, str2);
	cout << getLCS(str1, str2, len) << endl;

	return 0;
}