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
    bool checkMirror(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        return (root1->val == root2->val) and checkMirror(root1->left, root2->right) && checkMirror(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {

        return checkMirror(root, root);
    }
};