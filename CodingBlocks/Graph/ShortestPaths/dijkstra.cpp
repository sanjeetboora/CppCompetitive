//shortest path of all vertices from src vertex in a weighted graph
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
class graph
{	int V;
	unordered_map<T, list<pair<T, int> > > mp;
public:
	graph(int v) {
		V = v;
	}
	void addEdge(T u, T v, int wt, bool bidir = true) {
		mp[u].push_back(make_pair(v, wt));
		if (bidir) {
			mp[v].push_back(make_pair(u, wt));
		}
	}

	int dfsHelper(int src, unordered_map< int, pair<bool, int> > &visited, int &ans) {

		visited[src] = make_pair(true, 1);

		for (auto nbPair : mp[src]) {
			int nbr = nbPair.first;
			int wt = nbPair.second;
			if (!visited[nbr].first) {
				visited[src].second += dfsHelper(nbr, visited, ans);
				int nodesNbr = visited[nbr].second;
				int nodesLeft = V - nodesNbr;
				ans += 2 * min(nodesNbr, nodesLeft) * wt;
			}
		}
		return visited[src].second;
	}

	void dfs() {
		unordered_map< int, pair<bool, int> > visited;
		for (int i = 0; i < V; ++i)
		{
			visited[i] = make_pair(false, 0);
		}
		int ans = 0;
		dfsHelper(0, visited, ans);
		cout << ans << endl;
	}

	void printList() {
		for (auto v : mp) {
			T vertex = v.first;

			cout << vertex << endl;
			for (auto nbr : v.second) {
				cout << nbr.first << ", " << nbr.second << endl;
			}
			cout << endl;
		}
	}
};



int main(int argc, char const *argv[])
{	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {

		int n, h;
		cin >> n;
		h = n - 1;

		graph<int> g(n);

		while (h--) {
			int u, v, w;
			cin >> u >> v >> w;
			g.addEdge(u - 1, v - 1, w);

		}
		g.dfs();
		//g.printList();
	}

	return 0;
}