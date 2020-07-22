#include <iostream>
using namespace std;

#define inf 1e9

int minCost(int n, int k, int* height) {
	int* dp = new int[n + 1];
	dp[1] = 0;
	for (int i = 2; i <= n ; ++i)
	{	dp[i] = inf;
		for (int j = i - 1; j >= i - k and j >= 1; j--) {
			dp[i] = min(dp[i], dp[j] + abs(height[j] - height[i]));
		}
	}
	return dp[n];
}


int main() {
	int n, k;
	cin >> n >> k;
	int* height = new int[n + 1];
	for (int i = 1; i <= n ; ++i)
	{
		cin >> height[i];
	}
	cout << minCost(n, k, height) << endl;

}