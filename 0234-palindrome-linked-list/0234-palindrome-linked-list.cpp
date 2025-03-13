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
    ListNode* temp;
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Copy all values into an array
        vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }

        // Step 2: Use two-pointer technique to check for palindrome
        int left = 0, right = values.size() - 1;
        while (left < right) {
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    // Example: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    Solution solution;
    cout << (solution.isPalindrome(head) ? "True" : "False") << endl; // Output: True

    return 0;
}
