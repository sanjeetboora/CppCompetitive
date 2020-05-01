#include <bits/stdc++.h>
using namespace std;

class node {
public:
	char data;
	unordered_map<char, node*> children;
	bool isTerminal;
	int visited;
	node(char ch) {
		data = ch;
		isTerminal = false;
		visited  = 0;
	}

};

class trie
{
public:
	node* root;
	trie() {
		root = new node('\0');
	}
	void insert(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			if (!temp->children.count(word[i])) {
				node* child = new node(word[i]);
				temp->children[word[i]] = child;
			}
			temp = temp->children[word[i]];
			temp->visited = temp->visited + 1;
		}
		temp->isTerminal = true;
	}
	void uniquePrefixes(node* currNode, string prefix) {
		if (currNode == NULL) {
			return;
		}
		if (currNode->visited  == 1) {
			cout << prefix << endl;
			return;
		}
		for (auto x : currNode->children)
		{	char ch = x.first;
			uniquePrefixes(x.second, prefix + ch);
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
	trie t;
	int n, q;
	cin >> n;
	while (n--) {
		string word;
		cin >> word;
		t.insert(word);
	}
	t.uniquePrefixes(t.root, "");




	return 0;
}


//input
// 7
// abc
// applicant
// application
// app
// ape
// mango
// man


//output
// mang
// ape
// applicat
// applican
// ab

