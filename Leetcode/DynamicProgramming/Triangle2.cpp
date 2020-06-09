// Without any extra space
class Solution {
public:


    int minimumTotal(vector<vector<int>>& triangle) {

        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {

                int x = INT_MAX, y = INT_MAX;

                if (j < triangle[i - 1].size()) {
                    x = triangle[i - 1][j];
                }

                if (j - 1 >= 0) {
                    y = triangle[i - 1][j - 1];
                }

                triangle[i][j] += min(x, y);

            }
        }

        int ans = INT_MAX;

        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++) {
            if (triangle[triangle.size() - 1][j] < ans) {
                ans = triangle[triangle.size() - 1][j];
            }
        }

        return ans;

    }
};