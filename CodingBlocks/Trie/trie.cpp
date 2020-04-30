#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	char data;
	bool terminated;
	unordered_map<char, node*> children;

	node(char c) {
		data = c;
		terminated = true;

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
			char ch = word[i];
			if (temp->children.count(ch)) {
				temp = temp->children[ch];
			} else {
				node* child = new node(ch);
				temp->children[ch] = child;
				temp = child;
			}
		}
		temp->terminated = true;

	}

	bool search(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			char ch = word[i];
			if (temp->children.count(ch)) {
				temp = temp->children[ch];
			} else {
				return false;
			}
		}
		return temp->terminated;
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

	int n = 6;
	string arr[10] = {"app", "ape", "application", "mango", "apple", "man"};
	for (int i = 0; i < n; ++i)
	{
		t.insert(arr[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (t.search(str)) {
			cout << str << " found"  << endl;
		} else {
			cout << str << " not found"  << endl;
		}


	}


	return 0;
}







