//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";

        string s = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserial(string& data) {
        if (data[0] == '#') {
            if (data.length() > 1) {
                data = data.substr(2);
            }
            return nullptr;
        }
        else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = deserial(data);
            node->right = deserial(data);
            return node;

        }

    }
    TreeNode* deserialize(string data) {
        return deserial(data);
    }

    int helper(string& str) {
        int pos = str.find(',');
        int val = stoi(str.substr(0, pos));
        str = str.substr(pos + 1);
        return val;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



















