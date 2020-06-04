class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));


        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 and j != m - 1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                }
                else if ( j == m - 1 and i != n - 1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                }
                else if (i != n - 1 and j != m - 1) {
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                }
                else {
                    dp[i][j] = grid[i][j];
                }
            }
        }

        return dp[0][0];

    }


};