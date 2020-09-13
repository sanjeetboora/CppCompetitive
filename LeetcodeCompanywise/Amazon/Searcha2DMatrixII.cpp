//https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r = 0,  c = cols - 1;
        while (r >= 0 and r< rows and c >= 0 and c < cols ) {
            if (target == matrix[r][c]) {
                return true;
            }
            else if (target > matrix[r][c]) {
                r++;
            }
            else {
                c--;
            }
        }
        return false;
    }
};