#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int* wt, int* val, int n, int W) {
	if (n == 0) {
		return 0;
	}

	int inc = 0, exc = 0;

	if ((W - wt[n - 1]) >= 0) {
		inc = val[n - 1] + knapsackRec(wt, val, n - 1, W - wt[n - 1]);
	}
	exc =  knapsackRec(wt, val, n - 1, W);

	return max(inc, exc);

}

int knapsackBottomUp(int* wt, int* val, int n, int W) {

	int dp[n + 1][W + 1];
	if (n == 0) {
		return 0;
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
		}
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			int inc = 0, exc = 0;
			exc = dp[i - 1][j];

			if ((j - wt[i - 1]) >= 0 ) {
				inc = val[i - 1] + dp[i - 1][j - wt[i - 1]];
			}

			dp[i][j] = max(inc, exc);
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}
	return dp[n][W];

}




int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int wt[10] = {1, 2, 3};
	int val[10] = {6, 10, 12};
	int n = 3;
	int W = 5;

	cout << knapsackRec(wt, val, n, W) << endl;
	cout << knapsackBottomUp(wt, val, n, W) << endl;



	return 0;
}

//output
// 22

// 0, 0, 0, 0, 0, 0,
// 0, 6, 6, 6, 6, 6,
// 0, 6, 10, 16, 16, 16,
// 0, 6, 10, 16, 18, 22,
// 22

