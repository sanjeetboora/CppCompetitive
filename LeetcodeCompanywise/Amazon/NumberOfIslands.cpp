//https://leetcode.com/problems/number-of-islands/

//dfs
class Solution {
public:

	void dfs(vector<vector<char>>& grid, int r, int c) {
		int rows = grid.size();
		int cols = grid[0].size();

		if (r < 0  or r >= rows or c < 0 or c >= cols or grid[r][c] == '0' ) {
			return;
		}
		grid[r][c] = '0';
		dfs(grid, r - 1, c);
		dfs(grid, r + 1, c);
		dfs(grid, r, c - 1);
		dfs(grid, r, c + 1);
	}


	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0) {
			return 0;
		}
		int islands = 0;
		int rows = grid.size();
		int cols = grid[0].size();

		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				if (grid[r][c] == '1') {
					islands++;
					dfs(grid, r, c);
				}
			}
		}
		return islands;
	}
};