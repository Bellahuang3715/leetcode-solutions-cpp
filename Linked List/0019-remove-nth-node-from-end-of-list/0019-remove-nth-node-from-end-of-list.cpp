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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // calculate the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr)
        {
            current = current->next;
            length++;
        }
        
        // find the position of the node to remove
        int target = length - n;
        
        // if head is the target
        if (target == 0)
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // traverse to the node before target
        current = head;
        for (int i = 0; i < target-1; i++)
        {
            current = current->next;
        }
        
        // delete target node
        ListNode* targetNode = current->next;
        current->next = targetNode->next;
        delete targetNode;
        
        return head;
    }
};




/*
FAST AND SLOW POINTER APPROACH
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases (e.g., removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the `first` pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move both pointers until `first` reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        second->next = second->next->next;

        // Return the new head (skip the dummy node)
        return dummy->next;
    }
};
