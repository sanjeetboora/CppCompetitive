//https://leetcode.com/problems/maximum-average-subtree/
//https://leetcode.com/discuss/interview-question/349617

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
    //no. of nodes in subtree, sum of nodes in subtree
    pair<int, int> dfs(TreeNode* root, double &ans) {

        if (root-> left == NULL and root-> right == NULL) {
            pair<int, int> p = {1, root-> val};
            ans = max(ans, (root-> val * 1.0));
            return p;
        }
        pair<int, int>x = {0, 0};
        pair<int, int>y = {0, 0};
        if (root-> left) {
            x = dfs(root-> left, ans);
        }
        if (root-> right) {
            y = dfs(root-> right, ans);
        }
        pair<int, int> res;
        res.first = x.first + y.first + 1;
        res.second = x.second + y.second + root->val;

        double pans = (res.second * 1.0) / res.first;

        // cout<<res.first <<", "<<res.second<<", "<<pans<<", "<<ans<<endl;
        ans = max(ans, pans);

        return res;


    }

    double maximumAverageSubtree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        double ans  = 0;
        dfs(root, ans);
        return ans;
    }
};




//for N-ary tree
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
double ans = INT_MIN;
Node *res;
vector<double> dfs(Node *node) {
    if (!node) {
        return {0, 0};
    }
    double currVal = node->val;
    double count = 1;
    for (auto child : node->children) {
        vector<double> temp = dfs(child);
        count += temp[1];
        currVal += temp[0];
    }
    double avg = currVal / count;
    if (count > 1 && avg > ans) {
        ans = avg;
        res = node;
    }
    return {currVal, count};
}
int maximumAverageSubtree(Node *root) {
    if (!root) {
        return 0;
    }
    dfs(root);
    return res->val;
}