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
    // approach #1 -> hash O(n)
    // approach #2 -> Floyd's tortoise and hare O(1)
    bool hasCycle(ListNode *head) {
        // 2 pointers approach
        // slow pointer -> shifted by 1 each time
        // fast pointer -> shiftwd by 2 each time
        
        // slow pointer inc. distance by 1, fast pointer dec. distance by 2
        // (n+1)-2 => max n cycles for pointers to meet
        
        ListNode *slow, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;;
            if (slow == fast)
                return true;
        }
        return false;
    }
};