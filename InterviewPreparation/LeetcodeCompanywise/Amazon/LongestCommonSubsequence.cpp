class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int xl = x.length();
        int yl = y.length();
        int dp[xl + 1][yl + 1];
        for (int i = 0; i <= xl; i++) dp[i][0] = 0;
        for (int i = 0; i <= yl; i++) dp[0][i] = 0;

        for (int i = 1; i <= xl; i++) {
            for (int j = 1; j <= yl; j++) {

                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[xl][yl];
    }
};