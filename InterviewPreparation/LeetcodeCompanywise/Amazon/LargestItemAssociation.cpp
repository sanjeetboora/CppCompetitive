//https://leetcode.com/discuss/interview-question/782606/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template<typename T>
class graph
{	unordered_map<T, list<T> >mp;
public:
	void addEdge(T u, T v, bool bidir = true) {
		mp[u].push_back(v);
		if (bidir) {
			mp[v].push_back(u);
		}
	}

	void dfsHelper(T ver, unordered_map<T, bool> &visited, int &vCount, list<T> &ls) {
		visited[ver] = true;
		vCount++;
		ls.push_back(ver);
		for (auto nbr : mp[ver]) {
			if (!visited.count(nbr)) {
				dfsHelper(nbr, visited, vCount, ls);
			}
		}
		return;
	}

	list<T> connectedComponents() {
		unordered_map<T, bool> visited;
		list<T> ans;
		int maximumConnections = 0;
		for (auto v : mp)
		{
			int vCount = 0;
			list<T> ls;
			if (!visited.count(v.first)) {
				dfsHelper(v.first, visited, vCount, ls);
			}
			if (vCount > maximumConnections ) {
				maximumConnections = vCount;
				ans = ls;
			}

		}

		return ans;

	}

};



int main(int argc, char const *argv[])
{
	graph<string> g;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	list<string> ans = g.connectedComponents();

	for (auto i : ans)
	{
		cout << i << ", ";
	} cout << endl;

	return 0;
}


/*
3
item1 item2
item3 item4
item4 item5

*/

/*
4
item1 item2
item1 item4
item3 item4
item4 item5

*/



