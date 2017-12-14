// Time : O(m + n)
// Space : O(1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        while (l1 || l2 || up) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int s = a + b + up;
            current->next = new ListNode(s % 10);
            current = current->next;
            up = s / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        
        return head->next;
    }
};
