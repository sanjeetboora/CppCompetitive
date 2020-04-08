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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;

        if (root == NULL) {
            return v;
        }

        TreeNode* temp = root;
        while (temp || !st.empty()) {
            while (temp) {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            v.push_back(temp->val);
            st.pop();
            temp = temp->right;
        }
        return v;
    }
};