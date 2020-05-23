//https://www.hackerrank.com/challenges/journey-to-the-moon/problem

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
		//cout << src << ", ";
		visited[src] = true;
		verCount++;
		for (auto nbr : mp[src]) {
			if (!visited.count(nbr)) {
				dfsHelper(nbr, visited, verCount);
			}
		}
	}
	int dfs(int n) {

		unordered_map<T, bool> visited;

		int countries = 0;
		int pairsFromSameCountry = 0;
		int totalPossiblePairs = (n * (n - 1)) / 2;
		for (auto v : mp) {
			int astronaut = 0; //count of astronauts in a country
			if (!visited.count(v.first)) {
				//cout << countries << " --> ";
				dfsHelper(v.first, visited, astronaut);
				//cout << astronaut << endl;

				pairsFromSameCountry = (astronaut * (astronaut - 1)) / 2;
				totalPossiblePairs -= pairsFromSameCountry;

				//cout << pairsFromSameCountry << ", " << totalPossiblePairs << endl;
				countries++;
			}
		}
		return totalPossiblePairs;
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

	graph<int> g;
	int n, p;
	cin >> n >> p;
	while (p--) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);

	}

	cout << g.dfs(n) << endl;

	return 0;
}


//input
// 5 3
// 0 1
// 2 3
// 0 4

//output
//6


