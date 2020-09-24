//https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/

#include<bits/stdc++.h>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* If target is present in tree, then prints the ancestors
   and returns true, otherwise returns false. */
bool printAncestors(struct node *root, int target)
{
	if (root == NULL) {
		return false;
	}
	if (root->data == target) {
		// cout << root->data << ", ";
		return true;
	}

	if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
		cout << root->data << ", ";
		return true;
	}
	return false;
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
	struct node* node = (struct node*)
	                    malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Construct the following binary tree
	            1
	          /   \
	        2      3
	      /  \
	    4     5
	   /
	  7
	*/
	struct node *root = newnode(1);
	root->left        = newnode(2);
	root->right       = newnode(3);
	root->left->left  = newnode(4);
	root->left->right = newnode(5);
	root->left->left->left  = newnode(7);

	printAncestors(root, 7);
	return 0;
}