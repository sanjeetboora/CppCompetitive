//DFS - connected components


class Solution {
public:

    int dir[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            int row = r + dir[i][0], col = c + dir[i][1];
            if (row >= 0 and row< grid.size() and col >= 0 and col < grid[0].size() and grid[row][col] == '1') {
                cout << row << ", " << col << endl;
                dfs(grid, row, col);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        int rows = grid.size();
        if (rows == 0) {
            return islands;
        }
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;

    }
};









