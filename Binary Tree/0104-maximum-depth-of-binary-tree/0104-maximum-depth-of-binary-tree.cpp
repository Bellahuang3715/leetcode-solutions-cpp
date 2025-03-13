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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // If the tree is empty, the depth is 0

        queue<TreeNode*> q;  // Queue to perform level-order traversal
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            depth++; // Increment depth as we process each level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Add the left and right children to the queue if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return depth;
    }
};
