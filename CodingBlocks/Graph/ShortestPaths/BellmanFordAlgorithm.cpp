#include <bits/stdc++.h>
using namespace std;


class graph
{	int V;
	int E;
	int connectedComponents;
	vector<vector<int> > Edges;
public:
	graph(int n, int e) {
		V = n;
		E = e;
		Edges.reserve(e);
		connectedComponents = n;
	}

	void addEdge(int u, int v, int wt, int EdgeNum) {
		Edges[EdgeNum] = {u, v, wt};
	}

	void BellmanFord(int src) {
		vector<int> Dist(V);
		for (int i = 0; i < V; ++i)
		{
			if (i == src) {
				Dist[i] = 0;
			}
			else {
				Dist[i]  = INT_MAX;
			}
		}


		for (int i = 1; i <= V - 1; ++i)
		{
			for (int j = 0; j < E; ++j)
			{
				int src = Edges[j][0];
				int des = Edges[j][1];
				int wt = Edges[j][2];
				if (Dist[src] != INT_MAX and Dist[src] + wt < Dist[des]) {
					Dist[des] = Dist[src] + wt;
				}
			}
		}

		for (int i = 0; i < E; ++i)
		{
			int src = Edges[i][0];
			int des = Edges[i][1];
			int wt = Edges[i][2];
			if (Dist[src] != INT_MAX and Dist[src] + wt < Dist[des]) {
				cout << "negative cycle exists from " << src << " to " << des << endl;
				return;
			}
		}

		for (int i = 0; i < V; ++i)
		{
			cout << i << " - " << Dist[i] << endl;
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

	graph g(vertices, edges);



	for (int i = 0; i < edges; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w, i);
	}
	g.BellmanFord(0);


	return 0;
}


// input
// 7 8
// 0 1 4
// 0 6 2
// 1 2 3
// 2 3 3
// 3 5 -2
// 4 5 2
// 2 4 1
// 6 4 2

// output
// 0 - 0
// 1 - 4
// 2 - 7
// 3 - 10
// 4 - 4
// 5 - 6
// 6 - 2

// input
// 7 8
// 0 1 4
// 0 6 2
// 1 2 3
// 2 3 -3
// 3 5 -2
// 5 4 2
// 4 2 1
// 6 4 2

//output
//negative cycle exists from 2 to 3









