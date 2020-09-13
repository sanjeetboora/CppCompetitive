//https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int val = 1;
        vector<vector<int> > res;
        for (int i = 0; i < n; i++) {
            vector<int>x(n, 0);
            res.push_back(x);
        }
        int startrow = 0, startcol = 0, endrow = n - 1, endcol = n - 1;
        while (val <= n * n) {

            int x = startcol;
            while ( x <= endcol and val <= n * n) {
                res[startrow][x++] = val++;
            }
            startrow++;

            x = startrow;
            while (x <= endrow and val <= n * n) {
                res[x++][endcol] = val++;
            }
            endcol--;

            x = endcol;
            while (x >= startcol and val <= n * n) {
                res[endrow][x--] = val++;
            }
            endrow--;

            x = endrow;
            while (x >= startrow and val <= n * n) {
                res[x--][startcol] = val++;
            }
            startcol++;
        }
        return res;
    }
};