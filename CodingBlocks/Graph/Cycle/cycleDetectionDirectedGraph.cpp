#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class graph
{	unordered_map<int, list<int> > mp;
public:
	void addEdge(int u, int v, bool bidir = true) {
		mp[u].push_back(v);
		if (bidir) {
			mp[v].push_back(u);
		}
	}

	bool dfsHelper(int src, unordered_map<int, bool> &visited, vector<bool> &path) {
		visited[src] = true;
		path[src] = true;
		for (auto nbr : mp[src]) {
			if (path[nbr]) {
				return true;
			}
			if (!visited.count(nbr)) {
				if (dfsHelper(nbr, visited, path)) {
					return true;
				}
			}
		}
		path[src] = false;
		return false;
	}
	void dfs(int src) {
		unordered_map<int, bool> visited;
		vector<bool> v;
		v.reserve(100);
		if (dfsHelper(src, visited, v)) {
			cout << "cycle detected" << endl;
		}
		else {
			cout << "cycle doesn't exist" << endl;
		}
	}

	void printList() {
		for (auto v : mp) {
			int vertex = v.first;
			list<int> neighbours = v.second;
			cout << vertex << " --> ";
			for (int nbr : neighbours) {
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}
};



int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g;

	g.addEdge(1, 2, false);
	g.addEdge(2, 3, false);
	g.addEdge(1, 0, false);
	g.addEdge(0, 4, false);
	//g.addEdge(4, 1, false);
	g.addEdge(2, 0, false);


	g.printList();

	g.dfs(0);

	return 0;
}


