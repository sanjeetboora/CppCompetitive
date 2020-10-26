/* Problem -  */
/* By Sanjeet Boora */

#include<iostream>
using namespace std;

#define mod 1000000007

int totalPaths(int grid[1005][1005], int h, int w) {

	int dp[1005][1005] = {0};
	dp[h - 1][w - 1] = 0;
	dp[h - 1][w - 2] = 1;
	dp[h - 2][w - 1] = 1;
	for (int i = h - 1; i >= 0; i--) {
		for (int j = w - 1; j >= 0; j--) {
			if (grid[i][j] == 0) {
				if (i + 1 <= h - 1) {
					dp[i][j] += dp[i + 1][j];
				}
				if (j + 1 <= w - 1) {
					dp[i][j] = ((dp[i][j] % mod) + (dp[i][j + 1] % mod)) % mod;
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}

	return  dp[0][0];
}


int main() {
	int h, w;
	cin >> h >> w;
	int grid[1005][1005];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char x;
			cin >> x;
			x == '.' ? grid[i][j] = 0 : grid[i][j] = 1;
		}
	}
	cout << totalPaths(grid, h, w) << endl;
}