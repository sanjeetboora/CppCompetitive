//https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

//DFS - Inorder Traversal

class Solution {
public:
    Node* prev = NULL;
    Node* headLL = NULL;
    void treeToDoublyLinkedList(Node* root) {
        if (root == NULL) {
            return;
        }

        treeToDoublyLinkedList(root->left);
        if (prev == NULL) {
            headLL = root;
            prev = root;
        }
        else {
            root -> left = prev;
            prev -> right = root;
            prev = root;
        }

        treeToDoublyLinkedList(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return root;
        }
        treeToDoublyLinkedList(root);

        prev->right = headLL;
        headLL->left = prev;

        return headLL;

    }
};













