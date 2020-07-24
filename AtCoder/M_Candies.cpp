#include<iostream>
using namespace std;

#define mod 1000000007
#define ll long long int
ll totalWays(int* candies, int n, int k) {

	ll dp[n][k + 1];
	for (int i = 0; i <= k; i++) {
		dp[0][i] = candies[0] >= i ? 1 : 0;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = (mod + dp[i][j - 1] + dp[i - 1][j] - (j - 1 - candies[i] >= 0 ? dp[i - 1][j - 1 - candies[i]] : 0)) % mod;
			}
		}
	}

	return dp[n - 1][k];

}


int main() {
	int n, k;
	cin >> n >> k;
	int candies[n];
	for (int i = 0; i < n; i++) {
		cin >> candies[i];
	}
	cout << totalWays(candies, n, k) << endl;
}