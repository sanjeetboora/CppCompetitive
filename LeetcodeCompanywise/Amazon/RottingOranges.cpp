//https://leetcode.com/problems/rotting-oranges/
//https://leetcode.com/discuss/interview-question/411357/
//https://leetcode.com/discuss/interview-question/347457
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;
        vector<pair<int, int> > neighbours = {{0, -1,},
            { -1, 0,},
            {0, 1,},
            {1, 0,}
        };
        int fresh = 0;
        //push rotten oranges
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        q.push(make_pair(-1, -1));
        int time = 0;
        while (!q.empty()) {
            pair<int, int> currCell = q.front();
            q.pop();

            if (currCell.first == -1) {
                if (!q.empty()) {
                    time++;
                    q.push(make_pair(-1, -1));
                    continue;
                }
            }

            for (pair<int, int> p : neighbours) {
                if (currCell.first + p.first >= 0 and
                        currCell.first + p.first < grid.size() and
                        currCell.second + p.second >= 0 and
                        currCell.second + p.second < grid[0].size()) {
                    if (grid[currCell.first + p.first][currCell.second + p.second] == 1) {
                        grid[currCell.first + p.first][currCell.second + p.second] = 2;
                        fresh--;
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
        return fresh == 0 ? time : -1;

    }
};

