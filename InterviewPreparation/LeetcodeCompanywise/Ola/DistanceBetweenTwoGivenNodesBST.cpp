/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, int a, int b) {
        while (true) {
            if (root->val > a and root->val > b) {
                root = root->left;
            }
            else if (root->val < a and root->val < b) {
                root = root->right;
            }
            else {
                return root;
            }
        }
    }


    int getDist(TreeNode* src, int dest) {
        if (src->val == dest) return 0;
        TreeNode* node = src->left
        if (src < dest) {
            node = src -> right;
        }
        return 1 + getDist(node, dest);
    }

    int minDiffInBST(TreeNode* root) {

        if (root == NULL) {
            return NULL;
        }
        TreeNode* lc = lca(root, n1, n2);
        return getDist(lc, n1) + getDist(lc, n2);
    }


};