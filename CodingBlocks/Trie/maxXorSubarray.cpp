#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	unordered_map<int, node*> children;
	int prefixXorValue;
	node* left;
	node* right;
	node(int ch) {
		data = ch;
		left = right = NULL;
		prefixXorValue = 0;
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
		temp->prefixXorValue = num;
	}

	int xorQuery(int num) {
		node* temp = root;
		for (int m = 31; m >= 0 ; m--)
		{
			int currBit = (num >> m) & 1;
			if (currBit) {
				if (temp->left) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			else {
				if (temp->right) {
					temp = temp->right;
				}
				else {
					temp = temp->left;
				}
			}
		}
		return num xor temp->prefixXorValue;
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
	int preXor = 0;
	int maxSubarrayXor = INT_MIN;
	int arr[10] = {8, 1, 2, 12, 7, 6};

	for (int i = 0; i < n; ++i)
	{
		preXor = preXor xor arr[i];
		t.insert(preXor);
		maxSubarrayXor = max(maxSubarrayXor, t.xorQuery(preXor));
	}
	cout << maxSubarrayXor << endl;


	return 0;
}


// input
// {1, 2, 3, 4}
// output
// 7

// input
// {4, 6}
// output
// 6

// input
// {8, 1, 2, 12, 7, 6}
// output
// 15