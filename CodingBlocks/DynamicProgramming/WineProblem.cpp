#include <bits/stdc++.h>
using namespace std;

int maxProfit(int* arr, int start, int end, int day) {
	if (start > end) {
		return 0;
	}
	int startInc = (day * arr[start]) + maxProfit(arr, start + 1, end, day + 1);
	int endInc = (day * arr[end]) + maxProfit(arr, start, end - 1, day + 1);
	int ans = max(startInc, endInc);

	return ans;
}

int maxProfitTopDown(int* arr, int start, int end, int day, int dp[100][100]) {
	if (start > end) {
		return 0;
	}
	if (dp[start][end] != 0) {
		return dp[start][end];
	}
	int startInc = (day * arr[start]) + maxProfitTopDown(arr, start + 1, end, day + 1, dp);
	int endInc = (day * arr[end]) + maxProfitTopDown(arr, start, end - 1, day + 1, dp);
	int ans = max(startInc, endInc);
	dp[start][end] = ans;

	return ans;
}

int maxProfitBottomUp(int* arr, int num) {
	int dp[100][100] = {0};
	int year = num;
	for (int i = 0; i < num; ++i)
	{
		dp[i][i] = arr[i] * year;
	}
	year--;
	for (int window = 2; window <= num; window++)
	{
		int start = 0, end = num - window;
		while (start <= end) {
			int endOfWindow = start + window - 1;

			dp[start][endOfWindow] = max(
			                             (arr[start] * year) + dp[start + 1][endOfWindow],
			                             (arr[endOfWindow] * year) + dp[start][endOfWindow - 1]
			                         );
			start++;
		}
		year--;
	}
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}
	return dp[0][num - 1];
}






int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[10] = {2, 3, 5, 1, 4};
	int n = 5;
	cout << maxProfit(arr, 0, 4, 1) << endl;
	int dp[100][100] = {0};
	cout << maxProfitTopDown(arr, 0, 4, 1, dp) << endl;
	cout << maxProfitBottomUp(arr, n) << endl;


	return 0;
}

//output
// 50
// 50
// 10, 23, 43, 45, 50,
// 0, 15, 37, 40, 48,
// 0, 0, 25, 29, 41,
// 0, 0, 0, 5, 24,
// 0, 0, 0, 0, 20,
// 50

