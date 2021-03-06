#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	unordered_map<int, node*> children;
	bool isTerminal;
	node* left;
	node* right;
	node(int ch) {
		data = ch;
		isTerminal = false;
		left = right = NULL;
	}

};

class trie
{
public:
	node* root;
	trie() {
		root = new node('\0');
	}
	void insert(int num) {
		node* temp = root;
		for (int i = 31; i >= 0; i--)
		{
			int val = (num >> i) & 1;
			if (val) {
				if (temp->right == NULL) {
					node* bit = new node(1);
					temp->right = bit;
				}
				temp = temp->right;

			}
			else {
				if (temp->left == NULL) {
					node* bit = new node(0);
					temp->left = bit;
				}
				temp = temp->left;
			}

		}
		temp->isTerminal = true;
	}

	int maxXorPair(int* arr, int n) {
		int maxXor = 0;
		for (int i = 0; i < n; ++i)
		{
			int currXor = 0;
			node* temp = root;
			int num = arr[i];
			for (int m = 31; m >= 0 ; m--)
			{
				int currBit = (num >> m) & 1;
				if (currBit) {
					if (temp->left) {
						currXor += pow(2, m);
						temp = temp->left;
					}
					else {
						temp = temp->right;
					}
				}
				else {
					if (temp->right) {
						currXor += pow(2, m);
						temp = temp->right;
					}
					else {
						temp = temp->left;
					}
				}
			}
			maxXor = max(maxXor, currXor);
		}
		return maxXor;
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
	int n = 8;
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7};
	for (int i = 0; i < n; ++i)
	{
		t.insert(arr[i]);
	}
	cout << t.maxXorPair(arr, n) << endl;




	return 0;
}


// input
// {25, 10, 2, 8, 5, 3}

// output
// 28

// input
// {0,1, 2, 3, 4, 5, 6, 7}

// output
// 7