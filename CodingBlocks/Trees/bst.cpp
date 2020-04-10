#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


node* insert(node* root, int d) {
	if (root == NULL) {
		root = new node(d);
		return root;
	}
	if (d <= root->data) {
		root->left = insert(root->left, d);
	}
	else {
		root->right = insert(root->right, d);
	}
	return root;
}
node* buildBST() {
	node* root = NULL;
	int d;
	cin >> d;
	while (d != -1) {
		root = insert(root, d);
		cin >> d;
	}
	return root;
}
void print(node* root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->data << ", ";
	print(root->right);
}

node* search(node* root, int d) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == d) {
		return root;
	}
	else if (root->data > d) {
		return search(root->left, d);
	}
	else {
		return search(root->right, d);
	}
}

void levelOrderWithNextLine(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << front->data << ", ";

			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
		}
		q.pop();
	}
}

node* deleteInBst(node* root, int d) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data < d) {
		root->right =  deleteInBst(root->right, d);
	}
	else if (root->data > d) {
		root->left = deleteInBst(root->left, d);
	}
	else {
		// node is a leaf node
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		//node have only left child
		else if (root->left != NULL and root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		//node have only right child
		else if (root->left == NULL and root->right != NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		//node have both child
		else {
			node* temp = root->left;
			while (temp->right != NULL) {
				temp = temp->right;
			}
			root->data = temp->data;
			root->left = deleteInBst(root->left, root->data);
			return root;
		}
	}
	return root;
}

node* min(node* root) {
	if (root == NULL) {
		return root;
	}
	if (root->left == NULL) {
		return root;
	}
	return min(root->left);
}

node* max(node* root) {
	if (root == NULL) {
		return root;
	}
	if (root->right == NULL) {
		return root;
	}
	return max(root->right);
}

bool isBST(node* root, int minimum, int maximum) {
	if (root == NULL) {
		return true;
	}

	if (root->data >= minimum and root->data < maximum and isBST(root->left, minimum, root->data) and isBST(root->right, root->data, maximum)) {
		return true;
	}
	return false;
}


node* buildBinaryTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = buildBinaryTree();
	root->right = buildBinaryTree();

	return root;
}


class LinkedList
{
public:
	node* head;
	node* tail;
};

LinkedList flattenBT(node* root) {
	LinkedList l;
	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}

	else if (root->left == NULL and root->right == NULL) {
		l.head = l.tail = root;
		return l;
	}
	else if (root->left != NULL and root->right == NULL) {
		LinkedList temp = flattenBT(root->left);
		temp.tail->right = root;
		l.head = temp.head;
		l.tail = root;
		return l;
	}
	else if (root->left == NULL and root->right != NULL) {
		LinkedList temp = flattenBT(root->right);
		root->right = temp.head;
		l.head = root;
		l.tail = temp.tail;
		return l;
	}
	else {
		LinkedList temp1 = flattenBT(root->left);
		LinkedList temp2 = flattenBT(root->right);
		temp1.tail->right = root;
		root->right = temp2.head;
		l.head = temp1.head;
		l.tail = temp2.tail;
		return l;
	}
}

node* InorderSuccessor(node* root, int d) {
	node* target = search(root, d);

	if (target == NULL) {
		return NULL;
	}
	else {
		if (target->right != NULL) {
			node* temp = target->right;
			while (temp->left) {
				temp = temp->left;
			}
			return temp;
		}
		else {
			node* ancestor = NULL;
			node* successor = root;
			while (successor!=target) {
				if(successor->data > target->data){
					ancestor = successor;
					successor = successor->left;
					
				}
				else{
					successor = successor->right;
				}
			}
			return ancestor;
		}
	}
}


int main(int argc, char const *argv[])
{
	node* root = NULL;
	// root = insert(root, 11);
	// root = insert(root, 21);
	// root = insert(root, 10);
	// root = insert(root, 2);
	// root = insert(root, 0);
	//root = buildBST();
	//print(root);
	//cout << endl;
	// if (search(root, 11)) {
	// 	cout << "node found" << endl;
	// }
	// else {
	// 	cout << "node not found" << endl;
	// }
	// node* minimum = min(root);
	// if (minimum != NULL) {
	// 	cout << minimum->data << endl;
	// } else {
	// 	cout << "tree is empty" << endl;
	// }
	// node* maximum = max(root);
	// if (maximum != NULL) {
	// 	cout << maximum->data << endl;
	// } else {
	// 	cout << "tree is empty" << endl;
	// }
	//root = buildBinaryTree(); //10 3 1 -1 -1 4 -1 -1 15 12 -1 -1 16 -1 -1
	root = buildBST();
	//print(root);
	levelOrderWithNextLine(root);
	cout << endl;
	// if (isBST(root, INT_MIN, INT_MAX)) {
	// 	cout << "tree is a bst" << endl;
	// }
	// else {
	// 	cout << "tree is not a bst" << endl;
	// }
	//root = deleteInBst(root, 20);
	//levelOrderWithNextLine(root);

	// LinkedList ll = flattenBT(root);
	// node* l = ll.head;
	// while (l) {
	// 	cout << l->data << ", ";
	// 	l = l->right;
	// }
	node* successor = InorderSuccessor(root, 9);
	cout <<successor->data<< endl;

	return 0;
}





