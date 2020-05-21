//weighted graph using hashmap of lists

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
class graph
{	unordered_map<T, list<pair<T, int> > > mp;
public:
	void addEdge(T u, T v, int wt, bool bidir = true) {
		mp[u].push_back(make_pair(v, wt));
		if (bidir) {
			mp[v].push_back(make_pair(u, wt));
		}
	}

	void printList() {
		for (auto v : mp) {
			T vertex = v.first;
			list< pair<T, int> > neighbours = v.second;
			cout << vertex << " --> ";
			for (pair<T, int> nbr : neighbours) {
				cout << " { " << nbr.first << ", " << nbr.second << " } ";
			}
			cout << endl;
		}
	}
};



int main(int argc, char const *argv[])
{
	graph<string> g;

	g.addEdge("1", "2", 10, false);
	g.addEdge("2", "3", 20);
	g.addEdge("1", "0", 30);
	g.addEdge("0", "4", 40);

	g.printList();

	return 0;
}