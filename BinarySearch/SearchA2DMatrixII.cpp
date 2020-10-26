/* Problem - https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/ */
/* By Sanjeet Boora */
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = 0;
        if (r > 0) {
            c = matrix[0].size();
        }
        if (r == 0 or c == 0) {
            return false;
        }
        for (int i = 0; i < r; i++) {
            bool pos = binary_search(matrix[i].begin(), matrix[i].end(), target);
            if (pos) {
                return true;
            }
        }
        return false;
    }
};