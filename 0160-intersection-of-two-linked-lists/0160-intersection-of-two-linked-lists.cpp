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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        if (lenA > lenB)
            headA = advance(headA, lenA - lenB);
        else if (lenB > lenA)
            headB = advance(headB, lenB - lenA);
            
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
    
private:
    int getLength(ListNode *head)
    {
        int length = 0;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            length++;
            ptr = ptr->next;
        }
        return length;
    }
    ListNode *advance(ListNode *head, int steps)
    {
        ListNode *ptr = head;
        while (ptr != nullptr && steps)
        {
            ptr = ptr->next;
            steps--;
        }
        return ptr;
    }
};