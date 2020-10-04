#include <bits/stdc++.h>
using namespace std;
class cmp {
public:
	bool operator()(pair<int, pair<int, int> >a, pair<int, pair<int, int> >b) {
		return a.first > b.first;
	}
};


int dir[3][2] = {{1, 0}, {0, 1}, {1, 1}};



int minCost( int** cost, int r, int c, int m, int n) {
	int sum = 0;
	if (m < 0  or m > r or n<0 or n>c or r == 0 or c == 0 ) {
		return sum;
	}
	int dp[r][c];
	bool vis[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dp[i][j] = INT_MAX;
			vis[i][j] = false;
		}
	}

	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, cmp>q; //cost, x, y

	pair<int, int> p1 = make_pair(0, 0);
	q.push(make_pair(cost[0][0], p1));
	dp[0][0] = cost[0][0];

	while (!q.empty()) {

		pair<int, pair<int, int> > t = q.top();
		q.pop();
		int currR = t.second.first;
		int currC = t.second.second;
		if (!vis[currR][currC]) {
			vis[currR][currC] = true;
			for (int i = 0; i < 3; i++) {
				int x = currR + dir[i][0];
				int y = currC + dir[i][1];

				if (x < r and x >= 0 and y<c and y >= 0 and !vis[x][y]) {
					dp[x][y] = min(dp[x][y], dp[currR][currC] + cost[x][y]);
					pair<int, int> p = make_pair(x, y);
					q.push(make_pair(dp[x][y], p));
				}
			}
		}
	}
	return dp[m][n];

}

int main(int argc, char const *argv[])
{
	int r, c;
	cin >> r >> c;

	int **cost = new int*[r];
	for (int i = 0; i < r; i++) {
		cost[i] = new int[c];
		for (int j = 0; j < c; j++) {
			cin >> cost[i][j];
		}
	}

	int m, n;
	cin >> m >> n;
	cout << minCost(cost, r, c, m, n) << endl;

	return 0;
}