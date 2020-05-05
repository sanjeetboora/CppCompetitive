#include <bits/stdc++.h>
using namespace std;

int minStepsToOneRecursive(int n) {
	if (n == 1) {
		return 0;
	}
	int sub1 = INT_MAX, div3 = INT_MAX, div2 = INT_MAX;

	if (n % 3 == 0) {
		div3 = minStepsToOneRecursive(n / 3);
	}
	if (n % 2 == 0) {
		div2 = minStepsToOneRecursive(n / 2);
	}

	sub1 = minStepsToOneRecursive(n - 1);

	return 1 + min(div2, min(div3, sub1));
}

int minStepsToOneTopDown(int n, int* memo) {
	if (n == 1) {
		return 0;
	}
	if (memo[n]) {
		return memo[n];
	}
	int sub1 = INT_MAX, div3 = INT_MAX, div2 = INT_MAX;

	if (n % 3 == 0) {
		div3 = minStepsToOneRecursive(n / 3);
	}
	if (n % 2 == 0) {
		div2 = minStepsToOneRecursive(n / 2);
	}

	sub1 = minStepsToOneRecursive(n - 1);
	memo[n] = 1 + min(div2, min(div3, sub1));

	return memo[n];
}

int minStepsToOneBottomUp(int n) {

	int *dp = new int[n + 1];

	dp[1] = 0; dp[2] = 1; dp[3] = 1;

	for (int i = 4; i <= n; ++i)
	{
		int sub1 = INT_MAX, div3 = INT_MAX, div2 = INT_MAX;

		if (i % 3 == 0) {
			div3 = dp[i / 3];
		}
		if (i % 2 == 0) {
			div2 = dp[i / 2];
		}

		sub1 = dp[i - 1];
		dp[i] = 1 + min(div2, min(div3, sub1));
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

	int n;
	cin >> n;
	cout << minStepsToOneRecursive(n) << endl;
	int memo[1000] = {0};
	cout << minStepsToOneTopDown(n, memo) << endl;
	cout << minStepsToOneBottomUp(n) << endl;

	return 0;
}