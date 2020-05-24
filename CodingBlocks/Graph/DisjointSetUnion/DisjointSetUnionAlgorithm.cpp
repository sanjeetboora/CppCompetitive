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
	int n = 7;
	graph g(n);


	return 0;
}








