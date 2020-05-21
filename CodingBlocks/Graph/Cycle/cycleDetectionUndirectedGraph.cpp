#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
class graph
{	unordered_map<T, list<T> > mp;
public:
	void addEdge(T u, T v, bool bidir = true) {
		mp[u].push_back(v);
		if (bidir) {
			mp[v].push_back(u);
		}
	}

	bool dfsHelper(T src, unordered_map<T, bool> &visited, T parent) {
		visited[src] = true;
		for (auto nbr : mp[src]) {
			if (!visited.count(nbr)) {
				if (dfsHelper(nbr, visited, src)) {
					return true;
				}
			}
			else if (nbr != parent) {
				return true;
			}
		}
		return false;
	}
	void dfs(T src) {
		unordered_map<T, bool> visited;

		if (dfsHelper(src, visited, "")) {
			cout << "cycle detected" << endl;
		}
		else {
			cout << "cycle doesn't exist" << endl;
		}
	}

	void printList() {
		for (auto v : mp) {
			T vertex = v.first;
			list<T> neighbours = v.second;
			cout << vertex << " --> ";
			for (T nbr : neighbours) {
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

	graph<string> g;

	g.addEdge("1", "2", false);
	g.addEdge("2", "3");
	g.addEdge("1", "0");
	g.addEdge("0", "4");
	// g.addEdge("1", "3");

	g.printList();

	g.dfs("0");

	return 0;
}


