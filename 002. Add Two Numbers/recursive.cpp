// Time : O(m + n)
// Space : O(m + n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* helper(ListNode* l1, ListNode* l2, int up) {
        if (!l1 && !l2) {
            return up > 0 ? new ListNode(up) : nullptr;
        }
        
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        ListNode* head = l1 ? l1 : l2;
        head->val = (a + b + up) % 10;
        up = (a + b + up) / 10;
        head->next = helper(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, up);
        return head;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
};
