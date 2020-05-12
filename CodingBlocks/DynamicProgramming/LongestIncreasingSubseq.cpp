#include <bits/stdc++.h>
using namespace std;

int longestIncSubseq(int* arr, int n) {
	int* dp = new int[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
	}
	int maxLength = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], (dp[j] + 1));
			}
		}
		maxLength = max(maxLength, dp[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;
	return maxLength;
}

int longestIncSubseqOptimized(int* arr, int n) {

	vector<int> dp;
	dp.push_back(arr[0]);

	for (int i = 1; i < n; ++i)
	{
		auto idx = lower_bound(dp.begin(), dp.end(), arr[i]);
		if (idx == dp.end()) {
			dp.push_back(arr[i]);
		}
		else {
			*idx = arr[i];
		}
	}
	for (int i = 0; i < dp.size(); ++i)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;
	return dp.size();
}



int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << longestIncSubseq(arr, n) << endl;
	cout << longestIncSubseqOptimized(arr, n) << endl;

	return 0;
}


// input
// 10
// 10 20 9 33 21 50 41 60 80 6

// output
// 1, 2, 1, 3, 3, 4, 4, 5, 6, 1,
// 6


// input
// 6
// 50 3 10 7 40 50

// output
// 1, 1, 2, 2, 3, 4,
// 4


