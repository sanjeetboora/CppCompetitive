//https://leetcode.com/discuss/interview-question/347457
//https://leetcode.com/problems/rotting-oranges/
//https://leetcode.com/discuss/interview-question/411357/
//https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>
using  namespace  std;

int treasureIsland(vector<vector<char> >& grid) {
	queue<pair<int, int> > q;
	vector<pair<int, int> > neighbours = {{1, 0,}, {0, 1,}, {0, -1,}, { -1, 0,}};

	q.push(make_pair(0, 0));
	grid[0][0] = 'D';
	int count = 0;
	while (!q.empty()) {
		count++;
		for (int sz = q.size(); sz > 0; sz--) {

			pair<int, int> currCell = q.front();
			q.pop();

			for (pair<int, int> p : neighbours) {
				if (currCell.first + p.first >= 0 and
				        currCell.first + p.first < grid.size() and
				        currCell.second + p.second >= 0 and
				        currCell.second + p.second < grid[0].size()) {
					if (grid[currCell.first + p.first][currCell.second + p.second] == 'X') {

						return count;
					}
					else if (grid[currCell.first + p.first][currCell.second + p.second] == 'O') {
						grid[currCell.first + p.first][currCell.second + p.second] = 'D';
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
		cout << endl;
	}
	return -1;
}

int main(int argc, char const * argv[])
{
	vector<vector<char> > grid = {{'O', 'O', 'O', 'O'},
		{'D', 'O', 'D', 'O'},
		{'O', 'O', 'O', 'O'},
		{'X', 'D', 'D', 'O'}
	};
	cout << treasureIsland(grid) << endl;

	return 0;
}












