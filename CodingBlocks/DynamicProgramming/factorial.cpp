#include <iostream>
using namespace std;
int memo[1000] = {0};

int factTopDown(int n) {
	if (n == 0) {
		memo[n] = 1;
		return memo[n];
	}

	if (memo[n]) {
		return memo[n];
	}

	int factOfN = factTopDown(n - 1) * n;
	memo[n] = factOfN;
	return memo[n];

}

int factBottomUp(int n) {
	int *dp = new int[n + 1];
	dp[0] = 1;
	for (int i = 1; i <= n ; ++i)
	{
		dp[i]  = i * dp[i - 1];
	}
	return dp[n];
}

int factBottomUpSpaceOptimized(int n) {
	if (n == 0) {
		return 1;
	}
	int fact = 1;
	for (int i = 1; i <= n ; ++i)
	{
		fact *= i;
	}
	return fact;
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
	cout << factTopDown(n) << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << memo[i] << ",";
	}
	cout << endl;

	cout << factBottomUp(n) << endl;
	cout << factBottomUpSpaceOptimized(n) << endl;


	return 0;
}