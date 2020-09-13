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

    string preorder(TreeNode* x, bool isLeft) {
        if (x == NULL) {
            if (isLeft) {
                return "lnull";
            }
            else {
                return "rnull";
            }
        }

        return "#" + to_string(x->val) + " " + preorder(x->left, true) + " " + preorder(x->right, false);

    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        string sres =  preorder(s, true);
        string tres = preorder(t, true);

        if (sres.find(tres) != string::npos) {
            return true;
        }
        return false;


    }
};