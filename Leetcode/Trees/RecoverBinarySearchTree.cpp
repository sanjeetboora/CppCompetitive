/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* j = NULL;
    TreeNode* k = NULL;
    TreeNode* pred = NULL;
    void swap(TreeNode* a, TreeNode* b) {
        TreeNode* temp = new TreeNode(a->val);
        a->val = b->val;
        b->val = temp->val;
    }

    void swappedNodes(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        swappedNodes(root->left);
        if (pred != NULL and root->val < pred->val) {
            j = root;
            if (k == NULL) {
                k = pred;
            } else {
                return;
            }
        }
        pred = root;
        swappedNodes(root->right);
    }

    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        swappedNodes(root);
        swap(j, k);

    }
};