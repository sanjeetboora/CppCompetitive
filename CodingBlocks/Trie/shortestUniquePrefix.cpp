#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	char data;
	bool terminated;
	int visited;
	unordered_map<char, node*> children;

	node(char c) {
		data = c;
		terminated = true;
		visited = 1;
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
				temp->visited++;

			} else {
				node* child = new node(ch);
				temp->children[ch] = child;

			}
			temp = temp->children[ch];
		}
		temp->terminated = true;

	}
	void printUniquePrefixes(node* root, string* arr, string prefix) {
		if (root == NULL)
		{
			return;
		}
		if (root->visited == 1) {
			cout << prefix << endl;
			return;
		}

		for (auto ele : root->children) {

			printUniquePrefixes(ele.second, arr, prefix + ele.first);
		}



	}
	void uniquePrefixes(trie t, string* arr, int n, string prefix) {
		node* temp = root;

		for (int i = 0; i < n; ++i)
		{
			t.insert(arr[i]);
		}
		printUniquePrefixes(root, arr, "");

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

	t.uniquePrefixes(t, arr, 6, "");


	return 0;
}







