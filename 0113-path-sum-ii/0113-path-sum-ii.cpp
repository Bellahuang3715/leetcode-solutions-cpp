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
    vector<vector<int>> equalSum;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);// using dfs to traverse on each node
        return equalSum;
    }
    
    void dfs(TreeNode* root, int newTarget, vector<int>& path) {
        if (!root) return;
        path.push_back(root->val);
        newTarget -= root->val;
        // if current node is a leaf node
        if (!root->left && !root->right) { 
            if (newTarget == 0) {
                equalSum.push_back(path);                
            }
        }
        else {
            dfs(root->left, newTarget, path);
            dfs(root->right, newTarget, path);
        }
        path.pop_back(); // for the backtracking
    }
};
