#include<iostream>
using namespace std;

#define inf 1000000000

//O(N) extra space
int minCost(int n, int* height) {
	int* dp = new int[n + 1];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int op1 = dp[i - 1] + abs(height[i - 1] - height[i]);
		int op2 = i == 2 ? inf : dp[i - 2] + abs(height[i - 2] - height[i]);
		dp[i] = min(op1, op2);
	}
	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout << dp[i] << ", ";
	// }
	// cout << endl;
	return dp[n];
}

//O(1) extra space
int minCostOptimized(int n, int* height) {
	int cost1 = 0, cost2 = inf, cost3 = 0;
	for (int i = 2; i <= n; i++) {
		int op1 = cost1 + abs(height[i - 1] - height[i]);
		int op2 = i == 2 ? inf : cost2 + abs(height[i - 2] - height[i]);
		cost3 = min(op1, op2);
		cost2 = cost1;
		cost1 = cost3;
	}
	return cost3;
}


int main() {
	int n;
	cin >> n;
	int* height = new int[n + 1];
	for (int i = 1; i <= n ; ++i)
	{
		cin >> height[i];
	}
	cout << minCost(n, height) << endl;
	cout << minCostOptimized(n, height) << endl;
}