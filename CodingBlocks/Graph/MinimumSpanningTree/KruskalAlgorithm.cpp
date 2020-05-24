#include <bits/stdc++.h>
using namespace std;


class graph
{	int V;
	int connectedComponents;
	vector<int> parent;
public:
	graph(int n) {
		V = n;
		connectedComponents = n;
		parent.reserve(n);
		for (int i = 0; i < V; ++i)
		{
			parent[i] = i;
		}
	}

	int getSuperParent(int x) {
		if (x == parent[x]) {
			return x;
		}
		else {
			parent[x] = getSuperParent(parent[x]);
			return parent[x];
		}
	}

	void unite(int a, int b) {

		int parA = getSuperParent(a);
		int parB = getSuperParent(b);
		if (parA != parB) {
			parent[parA] = parB;
			connectedComponents--;
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

	int vertices, edges;
	cin >> vertices >> edges;

	graph g(vertices);
	vector<vector<int> > vec(edges);


	for (int i = 0; i < edges; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vec[i] = {w, u, v};
	}
	sort(vec.begin(), vec.end());

	int totalWt = 0;
	for (int i = 0; i < edges; ++i)
	{
		int x = vec[i][1];
		int y = vec[i][2];
		int wt = vec[i][0];

		if (g.getSuperParent(x) != g.getSuperParent(y)) {
			g.unite(x, y);
			totalWt += wt;
		}
	}
	cout << totalWt << endl;

	return 0;
}


// input
// 6 9
// 0 1 1
// 1 4 2
// 0 3 4
// 3 4 4
// 0 4 3
// 1 3 4
// 2 4 4
// 4 5 7
// 2 5 5

// output
// 16











