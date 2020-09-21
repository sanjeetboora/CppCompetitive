//https://leetcode.com/problems/walls-and-gates/
//https://leetcode.com/discuss/interview-question/411357/
//https://leetcode.com/discuss/interview-question/347457
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        int INF = 2147483647;
        queue<pair<int, int> > q;
        vector<pair<int, int> > neighbours = {{0, -1,},
            { -1, 0,},
            {0, 1,},
            {1, 0,}
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }

        q.push(make_pair(-1, -1));
        while (!q.empty()) {
            pair<int, int> currCell = q.front();
            q.pop();

            if (currCell.first == -1) {
                if (!q.empty()) {
                    q.push(make_pair(-1, -1));
                    continue;
                }
            }

            for (pair<int, int> p : neighbours) {
                if (currCell.first + p.first >= 0 and
                        currCell.first + p.first < grid.size() and
                        currCell.second + p.second >= 0 and
                        currCell.second + p.second < grid[0].size()) {
                    if (grid[currCell.first + p.first][currCell.second + p.second] == INF) {
                        grid[currCell.first + p.first][currCell.second + p.second] = grid[currCell.first][currCell.second] + 1;
                        q.push(make_pair(currCell.first + p.first, currCell.second + p.second));
                    }
                }

            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cout << grid[i][j] << ", ";
            }
            cout << endl;
        }

    }
};