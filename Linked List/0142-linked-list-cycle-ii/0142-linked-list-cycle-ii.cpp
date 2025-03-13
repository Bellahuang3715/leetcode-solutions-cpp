/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            // cycle detected -> now find the start
            if (fast == slow)
            {
                // to find the start of the cycle, move one pointer to the head
                slow = head;
                // move both pointers one step at a time
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                // both pointers now point to the start of the cycle
                return slow;
            }
        }
        return nullptr;
    }
};