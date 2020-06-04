class Solution {
public:
    int dp[102][102] = {0};

    int uniquePaths(int m, int n) {
        if (m == 1 or n == 1) {
            return 1;
        }
        if (m <= 0 || n <= 0) {
            return 0;
        }

        if (dp[m][n] != 0) {
            return dp[m][n];
        }

        dp[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        return dp[m][n];
    }

};