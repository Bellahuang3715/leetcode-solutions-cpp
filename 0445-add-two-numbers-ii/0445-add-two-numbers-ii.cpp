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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* current = NULL;
        ListNode* prev = NULL;
        while (s1.size() || s2.size() || carry) {
            int sum = carry;
            if (s1.size()) {
                sum += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            prev = new ListNode(sum % 10);
            prev->next = current;
            current = prev;
        }
        return current;
    }
};
