//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

//BFS using 2 Stacks

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if (root == NULL) return res;

        stack<TreeNode* >st1;
        stack<TreeNode* >st2;
        st1.push(root);
        while (!st1.empty() or !st2.empty()) {
            vector<int>x;
            while (!st1.empty()) {
                TreeNode* y = st1.top();
                x.push_back(y->val);
                st1.pop();
                if (y->left) {
                    st2.push(y->left);
                }
                if (y->right) {
                    st2.push(y->right);
                }
            }
            if (x.size() >= 1) {
                res.push_back(x);
            }
            vector<int>x1;
            while (!st2.empty()) {
                TreeNode* y = st2.top();
                x1.push_back(y->val);
                st2.pop();
                if (y->right) {
                    st1.push(y->right);
                }
                if (y->left) {
                    st1.push(y->left);
                }
            }
            if (x1.size() >= 1) {
                res.push_back(x1);
            }
        }
        return res;
    }
};

/*****************************************************************/

//BFS - Using 1 Queue

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> x(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* f = q.front();
                q.pop();

                int idx = leftToRight == 1 ? i : (sz - 1 - i);
                x[idx] = f->val;
                if (f->left) {
                    q.push(f->left);
                }
                if (f->right) {
                    q.push(f->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(x);
        }
        return res;
    }
};