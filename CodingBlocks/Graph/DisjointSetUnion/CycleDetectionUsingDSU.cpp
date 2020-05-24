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

	int n, edges;
	cin >> n >> edges;
	graph g(n);
	bool cycle = false;
	for (int i = 0; i < edges; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (g.getSuperParent(x) != g.getSuperParent(y)) {
			g.unite(x, y);
		}
		else {
			cycle = true;
			cout << "cycle exists" << x << ", " << y << endl;
		}
	}
	if (cycle) {
		cout << "this is a cyclic graph" << endl;
	}
	else {
		cout << "this is an acyclic graph" << endl;
	}


	return 0;
}



// input
// 7 7
// 0 1
// 1 2
// 2 3
// 3 1
// 4 5
// 5 6
// 6 4

// output
// cycle exists3, 1
// cycle exists6, 4
// this is a cyclic graph






