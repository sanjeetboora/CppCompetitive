/* Problem -  */
/* By Sanjeet Boora */

#include<iostream>
#include <list>
#include <unordered_map>
using namespace std;

class graph {
public:
	int v;
	int e;
	unordered_map<int, list<int> > gp;
	int dp[100005] = {0};

	graph(int n, int m) {
		v = n;
		e = m;
	}

	void addEdge(int x, int y) {
		gp[x].push_back(y);
	}

	int pathLength(int x, int ans) {
		ans = 0;
		for (int y : gp[x]) {
			if (dp[y] == 0) {
				dp[y] += pathLength(y, 0);
			}
			dp[x] = max(dp[x], dp[y] + 1);
		}
		return ans;
	}
	int maxPath() {

		for (auto p : gp) {
			pathLength(p.first, 0);
		}
		int ans = 0;
		for (int i = 0; i <= v; i++) {
			// cout << i << " --> " << dp[i] << endl;
			ans = max(ans, dp[i]);
		}
		return ans;
	}

};

int main() {
	int n, m;
	cin >> n >> m;
	graph g(n, m);
	while (m--) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	cout << g.maxPath() << endl;
}