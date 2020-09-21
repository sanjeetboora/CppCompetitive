//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// /https://leetcode.com/discuss/interview-question/376375/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        int rVal = root->val;

        if (pVal < rVal and qVal < rVal) { //left
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (pVal > rVal and qVal > rVal) { //right
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return root;
        }


    }
};


//Iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        TreeNode* temp = root;

        while (temp != NULL) {
            int rVal = temp->val;
            if (pVal < rVal and qVal < rVal) { //left
                temp = temp->left;
            }
            else if (pVal > rVal and qVal > rVal) { //right
                temp = temp->right;
            }
            else {
                return temp;
            }
        }
        return NULL;
    }
};