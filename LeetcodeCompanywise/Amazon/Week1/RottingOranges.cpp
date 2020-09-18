//https://leetcode.com/problems/rotting-oranges/

/* BFS */
class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {

        int sz = grid.size();
        if (!sz) return 0;
        int fresh = 0;
        queue<pair<int, int> >q;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        q.push({ -1, -1});

        int steps = 0;
        while (!q.empty()) {
            pair<int, int>p = q.front();
            q.pop();

            if (p.first == -1) {
                if (q.size() > 0) {
                    q.push({ -1, -1});
                }
                steps++;
            }
            for (int i = 0; i < 4; i++) {
                int x = p.first + dir[i][0];
                int y = p.second + dir[i][1];
                if (x >= 0 and x < sz and y >= 0 and y < grid[0].size() and grid[x][y] == 1) {
                    grid[x][y] = 2;
                    fresh--;
                    q.push({x, y});
                }
            }
        }

        if (fresh > 0) {
            return -1;
        }
        return steps - 1;
    }
};











