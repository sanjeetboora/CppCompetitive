#include <bits/stdc++.h>
using namespace std;

int maxProfit(int* arr, int n) {
	if (n == 0) {
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int totalProfit = arr[i] + maxProfit(arr, n - i);
		ans = max(totalProfit, ans);
	}
	return ans;
}


int maxProfitTopDown(int* arr, int n, int* dp) {
	if (n == 0) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int totalProfit = arr[i] + maxProfitTopDown(arr, n - i, dp);
		ans = max(totalProfit, ans);
	}
	dp[n] = ans;
	return ans;
}


int maxProfitTopDown(int* arr, int n) {
	int dp[100] = {0};
	for (int i = 1; i <= n; ++i)
	{	int ans = 0;
		for (int cut = 1; cut <= i; ++cut)
		{
			ans = max(ans, arr[cut] + dp[i - cut]);
		}
		dp[i] = ans;
	}
	return dp[n];
}




int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[10] = {0, 1,   5,   8,   9,  10,  17,  17,  20};
	int n = 8;
	cout << maxProfit(arr, n) << endl;
	int dp[100];
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = -1;
	}
	cout << maxProfitTopDown(arr, n, dp) << endl;
	cout << maxProfitTopDown(arr, n) << endl;


	return 0;
}

//output
//22
