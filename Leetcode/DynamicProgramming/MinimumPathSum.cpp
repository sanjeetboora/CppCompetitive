class Solution {
public:

    int helper(vector<vector<int>>& grid, int sr, int sc, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        //base case

        if (sr == n - 1 and sc == m - 1) {
            return grid[n - 1][m - 1];
        }
        if (sr > n - 1 or sc > m - 1) {
            return INT_MAX;
        }

        if (dp[sr][sc] != -1) {
            return dp[sr][sc];
        }

        int val = grid[sr][sc];
        int right = helper(grid, sr, sc + 1, dp);
        int down = helper(grid, sr + 1, sc, dp);
        dp[sr][sc] = val + min(right, down);

        return dp[sr][sc];

    }



    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(grid, 0, 0, dp);


    }


};