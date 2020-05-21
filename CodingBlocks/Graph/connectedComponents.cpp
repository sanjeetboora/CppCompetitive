//print and count all connected components of the given graph
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

	void dfsHelper(T src, unordered_map<T, bool> &visited, int &verCount) {
		cout << src << ", ";
		visited[src] = true;
		verCount++;
		for (auto nbr : mp[src]) {
			if (!visited.count(nbr)) {
				dfsHelper(nbr, visited, verCount);
			}
		}
	}
	void dfs() {

		unordered_map<T, bool> visited;

		int count = 0;
		for (auto v : mp) {
			int verCount = 0; //count of vertices in a component
			if (!visited.count(v.first)) {
				cout << "component-" << count << " --> ";
				dfsHelper(v.first, visited, verCount);
				cout << " --> " << verCount << endl;
				count++;
			}

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
	g.addEdge("1", "3");
	g.addEdge("1", "3");
	g.addEdge("7", "8");
	g.addEdge("7", "9");
	g.addEdge("11", "12");

	g.printList();

	g.dfs();

	return 0;
}


