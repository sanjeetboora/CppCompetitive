#include <bits/stdc++.h>
using namespace std;

int mcm(int* arr, int n) {
	n--;
	int **dp = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = new int[n];
	}


	for (int i = 1; i < n; ++i)
	{
		int r = 0, c = i;

		while (c < n) {
			int res = INT_MAX;
			for (int pivot = r; pivot < c; pivot++)
			{
				res = min(res, dp[r][pivot] + dp[pivot + 1][c] +  (arr[r] * arr[pivot + 1] * arr[c + 1]));

			}
			//cout << "(" << r << "," << c << ")" << res << endl;
			dp[r][c] = res;
			r++; c++;
		}
	}

	return dp[0][n - 1];
}



int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[10] = {4, 2, 3, 1, 3};
	int n = 5;
	cout << mcm(arr, n) << endl;


	return 0;
}
