// O(Number of Elemnts) solution

class Solution {
public:


    int minPath(vector<vector<int>>& triangle, int i, int j, int** dp) {
        if (i == triangle.size() || j == triangle[i].size()) {
            return 0;
        }
        if (dp[i][j]) {
            return dp[i][j];
        }
        int x = minPath(triangle, i + 1, j + 1, dp);
        int y = minPath(triangle, i + 1, j, dp);

        int num = min(x, y);
        dp[i][j] = num + triangle[i][j];
        return dp[i][j];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int **dp = new int*[triangle.size()];

        for (int i = 0; i < triangle.size(); i++) {
            dp[i] = new int[triangle[i].size()];
        }

        for (int i = 0; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = 0;
            }
        }

        return minPath(triangle, 0, 0, dp);

    }
};