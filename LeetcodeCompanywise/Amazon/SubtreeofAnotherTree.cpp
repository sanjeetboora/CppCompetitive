https://leetcode.com/problems/subtree-of-another-tree/
// O(m^2+n^2+m*n)

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


//--------- Another Optimised Version -----------
// O(m*n)

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

    bool equal(TreeNode* x, TreeNode* y) {
        if (x == NULL and y == NULL) return true;
        if (x == NULL or y == NULL) return false;

        return (x->val == y->val) and equal (x->left, y->left) and equal(x->right, y->right);


    }

    bool isSubtree(TreeNode* s, TreeNode* t) {

        return s != NULL and (equal(s, t) or isSubtree(s-> left, t) or isSubtree(s->right, t));

    }
};