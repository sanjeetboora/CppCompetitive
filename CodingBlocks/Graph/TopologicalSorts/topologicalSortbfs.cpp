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

	void bfs() {
		unordered_map<T, int> indegree;
		list<T> l;

		for (auto v : mp) { //intially set indegree of all vertices as zero
			indegree[v.first] = 0;
		}

		for (auto v : mp) {
			for (T nbr : v.second) {
				indegree[nbr]++;
			}

		}

		queue<T> q;
		for (auto v : mp) {
			if (indegree[v.first] == 0) {
				q.push(v.first);
			}
		}

		while (!q.empty()) {
			T frontNode = q.front();
			q.pop();
			l.push_back(frontNode);
			for (T nbr : mp[frontNode]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

		for (string s : l) {
			cout << s << ", ";
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

	g.addEdge("student", "python", false);
	g.addEdge("student", "java", false);
	g.addEdge("student", "C++", false);
	g.addEdge("python", "DSAlgo", false);
	g.addEdge("java", "DSAlgo", false);
	g.addEdge("C++", "DSAlgo", false);
	g.addEdge("DSAlgo", "Javascript", false);
	g.addEdge("DSAlgo", "django", false);
	g.addEdge("DSAlgo", "web", false);
	g.addEdge("student", "Javascript", false);
	g.addEdge("Javascript", "web", false);
	g.addEdge("flutter", "web", false);


	g.printList();

	g.bfs();

	return 0;
}


