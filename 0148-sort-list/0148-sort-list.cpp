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
class Solution {
public:
    // approach: merge sort
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        if (l1 != nullptr) { current->next = l1; }
        if (l2 != nullptr) { current->next = l2; }
        
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) { return head; }
        
        // find the middle using fast and slow pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middle = slow->next;
        slow->next = nullptr;
        
        // split into left and right lists
        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);
        
        return merge(left, right);
    }
};