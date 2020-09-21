//https://leetcode.com/problems/critical-connections-in-a-network/


class Solution {
public:
	void dfs(unordered_map<int, list<int> > &mp, int curr, int par, unordered_map<int, int>& discTime, unordered_map<int, int>& lowTime) {
		discTime[curr] = discTime[par] + 1;
		lowTime[curr] = discTime[curr];
		for (int nbr : mp[curr]) {
			if (nbr == par) continue;

			if (!discTime.count(nbr)) {
				dfs(mp, nbr, curr, discTime, lowTime);
			}

			lowTime[curr] = min(lowTime[curr], lowTime[nbr]);
		}
	}


	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		vector<vector<int>> result;
		if (!connections.size()) return result;

		unordered_map<int, list<int> >mp;
		for (int i = 0; i < connections.size(); i++) {
			mp[connections[i][0]].push_back(connections[i][1]);
			mp[connections[i][1]].push_back(connections[i][0]);
		}
		unordered_map<int, int>discTime;
		unordered_map<int, int>lowTime;

		discTime[0] = 0;
		dfs(mp, 0, 0, discTime, lowTime);

		for (pair<int, list<int> > x : mp) {
			for (int y : x.second) {
				if (discTime[x.first] < lowTime[y]) {
					result.push_back({x.first, y});
				}
			}
		}
		return result;

	}
};



/*  Fast  */

const int N = 100005;
class Solution {
public:
	vector<int> g[N];
	int dt[N];
	int lt[N];
	vector<vector<int> > res;
	int t = 0;
	void dfs(int c, int p) {
		dt[c] = lt[c] = ++t;

		for (int x : g[c]) {
			if (x == p) continue;

			else if (!dt[x]) {
				dfs(x, c);
			}

			if (lt[x] > dt[c]) {
				res.push_back({c, x});
			}
			lt[c] = min(lt[c], lt[x]);

		}

	}

	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		for (auto x : connections) {
			g[x[0]].push_back(x[1]);
			g[x[1]].push_back(x[0]);
		}

		dfs(0, 0);
		return res;
	}
};





