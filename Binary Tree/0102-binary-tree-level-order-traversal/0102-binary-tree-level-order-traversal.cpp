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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) { return result; }
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {  
            vector<int> row;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
                row.push_back(node->val);
            }
            result.push_back(row);
            
        }
        return result;
    }
};



/*
RECURSIVE APPROACH
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, 0, result);
        return result;
    }

private:
    void traverse(TreeNode* node, int level, vector<vector<int>>& result) {
        if (!node) return;

        // Ensure the result vector has enough levels
        if (result.size() == level) {
            result.push_back({});
        }

        // Add the current node's value to the corresponding level
        result[level].push_back(node->val);

        // Recur for left and right subtrees
        traverse(node->left, level + 1, result);
        traverse(node->right, level + 1, result);
    }
};
