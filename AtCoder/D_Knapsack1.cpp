#include<iostream>
using namespace std;

#define ll long long int
ll dp[105][100005] = {0};
ll knapsack(int n, int W, int* wt, int* val) {

	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= W; w++) {
			if (w >= wt[i - 1]) {
				dp[i][w] = val[i - 1] + dp[i - 1][w - wt[i - 1]];
			}

			dp[i][w] = max(dp[i][w], dp[i - 1][w]);
		}
	}
	return dp[n][W];
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