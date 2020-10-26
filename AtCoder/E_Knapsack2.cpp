/* Problem -  */
/* By Sanjeet Boora */

#include<iostream>
using namespace std;

#define inf 1000000007
#define ll long long int


ll knapsack(int n, int W, int* wt, int* val) {
	int maxVal = n * 1000;
	ll dp[n + 1][maxVal + 1];

	for (int v = 0; v <= maxVal; v++) {
		dp[1][v] = inf;
	}
	dp[1][0] = 0;
	dp[1][val[0]] = wt[0];

	for (int i = 2; i <= n; ++i)
	{
		for (int v = 0; v <= maxVal; v++) {
			dp[i][v] = dp[i - 1][v];
			if (val[i - 1] > v) {
				continue;
			}
			dp[i][v] = min(dp[i - 1][v], wt[i - 1] + dp[i - 1][v - val[i - 1]]);
		}
	}

	int ans = 0;
	for (int v = 0; v <= maxVal; v++) {
		if (dp[n][v] <= W) {
			ans = v;
		}
	}
	return ans;

}

int main() {
	int n, W;
	cin >> n >> W;
	int* wt = new int[n];
	int* val = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}

	cout << knapsack(n, W, wt, val) << endl;

	return 0;
}