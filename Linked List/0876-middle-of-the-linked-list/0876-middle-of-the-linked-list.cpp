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
    ListNode* middleNode(ListNode* head) {
        // find the length of the linked list
        ListNode* ptr = head;
        int len = 0, middle;
        while (ptr != NULL) {
            len++;
            ptr = ptr->next;
        }
        middle = len / 2;
        int count = 0;
        ListNode* ptr2 = head;
        while (ptr2 != NULL) {
            if (count == middle) {
                return ptr2;
            }
            ptr2 = ptr2->next;
            count++;
        }
        return NULL;
    }
};