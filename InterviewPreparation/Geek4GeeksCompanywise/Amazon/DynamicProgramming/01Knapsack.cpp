//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005] = {0};
int knapsack01(int n, int* val, int*wt, int W) {

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            int inc = 0, exc = 0;
            if (wt[i - 1] <= w) {
                inc = val[i - 1] + dp[i - 1][w - wt[i - 1]];
            }
            exc = dp[i - 1][w];

            dp[i][w] = max(inc, exc);
            // cout<<dp[i][w]<<",";
        }
        // cout<<endl;
    }
    int res = dp[n][W];
    return res;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, W;
        cin >> n >> W;
        int val[n], wt[n];

        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> wt[i];
        }

        cout << knapsack01(n, val, wt, W) << endl;
    }


    return 0;
}