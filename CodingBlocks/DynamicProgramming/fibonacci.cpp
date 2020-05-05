#include <iostream>
using namespace std;

int fibTopDown(int n, int* memo) {
	if (n == 0 || n == 1) {
		memo[n] = n;
		return n;
	}

	if (memo[n]) {
		return memo[n];
	}

	int nthFib = fibTopDown(n - 1, memo) + fibTopDown(n - 2, memo);
	memo[n] = nthFib;
	return memo[n];
}


int fibBottomUp(int n) {
	int* dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}


	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << ",";
	}
	cout << endl;
	return dp[n];

}

int fibBottomUpSpaceOptimized(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	int a = 0, b = 1, c;

	for (int i = 2; i <= n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
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
	int memo[1000] = {0};
	cout << fibTopDown(n, memo) << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << memo[i] << ",";
	}
	cout << endl;

	cout << fibBottomUp(n) << endl;
	cout << fibBottomUpSpaceOptimized(n) << endl;

	return 0;
}