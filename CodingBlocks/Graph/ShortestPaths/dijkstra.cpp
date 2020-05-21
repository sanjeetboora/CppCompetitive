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

	void dijkstra(T src) {
		set<pair<T, int> > disSet;
		unordered_map<T, int>dist;
		for (auto v : mp) {
			dist[v.first] = INT_MAX;
		}
		dist[src] = 0;
		disSet.insert(make_pair(dist[src], src));
		while (!disSet.empty()) {
			auto front = *(disSet.begin());
			T node = front.second;
			int nodeDis = front.first;
			disSet.erase(disSet.begin());

			for (auto nbr : mp[node]) {
				if ((nbr.second + nodeDis) < dist[nbr.first]) {
					auto fInSet = disSet.find(make_pair(dist[nbr.first], nbr.first));
					if (fInSet != disSet.end()) {
						disSet.erase(fInSet);
					}
					dist[nbr.first] = nbr.second + nodeDis;
					disSet.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}
		}

		for (auto v : dist) {
			cout << v.first << ", " << v.second << endl;
		}

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
			g.addEdge(u, v, w);

		}
		g.dijkstra(0);
		//g.printList();
	}

	return 0;
}



//input
// 1
// 5
// 0 1 2
// 1 2 2
// 2 3 2
// 0 3 8
// 0 2 5


//output
// 0, 0
// 1, 2
// 2, 4
// 3, 6
