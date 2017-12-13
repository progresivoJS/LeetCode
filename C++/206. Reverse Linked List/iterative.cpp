// Time : O(n)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* pre = nullptr;
        while (head) {
            newHead = new ListNode(head->val);
            head = head->next;
            if (pre) newHead->next = pre;
            pre = newHead;
        }
        return newHead;
    }
};