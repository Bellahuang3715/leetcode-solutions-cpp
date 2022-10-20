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
    void postorderHelper(TreeNode* root, vector<int> &nodes) {
        if (root == NULL) {
            return;
        }
        postorderHelper(root->left, nodes);
        postorderHelper(root->right, nodes);
        nodes.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorderHelper(root, nodes);
        return nodes;
    }
};