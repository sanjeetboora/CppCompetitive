class Solution {
public:


    int minPath(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size() || j == triangle[i].size()) {
            return 0;
        }

        int x = minPath(triangle, i + 1, j + 1);
        int y = minPath(triangle, i + 1, j);

        int num = min(x, y);
        return num + triangle[i][j];

    }
    int minimumTotal(vector<vector<int>>& triangle) {

        return minPath(triangle, 0, 0);

    }
};