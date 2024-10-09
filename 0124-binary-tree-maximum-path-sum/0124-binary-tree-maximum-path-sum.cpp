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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;   // smallest possible int value (from <climits>)
        maxGain(root, maxSum);
        return maxSum;
    }
    
    int maxGain(TreeNode* node, int& maxSum)
    {
        if (!node) { return 0; }
        // calculate max gain from left and right children
        int leftGain = std::max(maxGain(node->left, maxSum), 0);
        int rightGain = std::max(maxGain(node->right, maxSum), 0);
        int currentPathSum = node->val + leftGain + rightGain;
        
        maxSum = std::max(maxSum, currentPathSum);
        return node->val + std::max(leftGain, rightGain);
        
    }
};