/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* findMiddleEle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // disconnect left half from the middle
        if (prev != nullptr)
        {
            prev->next = nullptr;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == nullptr) { return nullptr; }
        if (head->next == nullptr)
        {
            return new TreeNode(head->val);
        }
        ListNode* mid = findMiddleEle(head);
        TreeNode* node = new TreeNode(mid->val);
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);
        return node;
    }
};