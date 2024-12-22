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
    // recursive function
    bool isValidBST(TreeNode* root, long long min, long long max)
    {
        if (!root) { return true; }
        if (root->val <= min || root->val >= max) { return false; }
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root)
    {
        return isValidBST(root, std::numeric_limits<long long>::min(), 
                      std::numeric_limits<long long>::max());
    }
};