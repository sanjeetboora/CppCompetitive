//bfs traversal unweighted graph using hashmap of lists
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

	void bfs(T src) {

		unordered_map<T, bool> visited;

		queue<T> q;
		q.push(src);
		visited[src] =  true;

		while (!q.empty()) {
			T frontVertex = q.front();
			q.pop();
			cout << frontVertex << ", ";
			for (T ver : mp[frontVertex]) {
				if (!visited.count(ver)) {
					q.push(ver);
					visited[ver] = true;
				}
			}
		}
		cout << endl;
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

	g.printList();

	g.bfs("0");

	return 0;
}


