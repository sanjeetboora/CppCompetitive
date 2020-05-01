#include <bits/stdc++.h>
using namespace std;

class node {
public:
	char data;
	unordered_map<char, node*> children;
	bool isTerminal;
	node(char ch) {
		data = ch;
		isTerminal = false;
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
		}
		temp->isTerminal = true;
	}

	bool search(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			if (!temp->children.count(word[i])) {
				return false;
			}
			temp = temp->children[word[i]];
		}
		return temp->isTerminal;
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
	cout << n << endl;
	while (n--) {
		string word;
		cin >> word;
		t.insert(word);
	}
	cin >> q;
	while (q--) {
		string word;
		cin >> word;
		if (t.search(word)) {
			cout << word << " found" << endl;
		}
		else {
			cout << word << " not found" << endl;
		}
	}

	return 0;
}



//input
// 6
// abc
// application
// app
// ape
// mango
// man
// 4
// web
// app
// applicant
// mango