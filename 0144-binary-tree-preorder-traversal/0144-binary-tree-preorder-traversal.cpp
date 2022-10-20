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
    void preorderHelper(TreeNode* root, vector<int> &nodes) {
        if (root == NULL) return;
        nodes.push_back(root->val);
        preorderHelper(root->left, nodes);
        preorderHelper(root->right, nodes);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorderHelper(root, nodes);
        return nodes;
    }
};