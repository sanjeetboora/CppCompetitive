//unweighted graph using array of lists
#include <bits/stdc++.h>
using namespace std;

class graph
{	int V;
	list<int>* l;
public:
	graph(int vertices) {
		V = vertices;
		l = new list<int>[V];
	}

	void addEdge(int u, int v, bool bidir = true) {
		l[u].push_back(v);
		if (bidir) {
			l[v].push_back(u);
		}
	}

	void printList() {
		for (int i = 0; i < V; ++i) {
			int vertex = i;
			cout << vertex << " --> ";
			for (int nbr : l[i]) {
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}

};


int main(int argc, char const *argv[])
{	graph g(5);

	g.addEdge(1, 2, false);
	g.addEdge(2, 3);
	g.addEdge(1, 0);
	g.addEdge(0, 4);

	g.printList();

	return 0;
}