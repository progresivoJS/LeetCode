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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current) {
            ListNode* hop = current->next;
            while (hop) {
                if (current->val == hop->val) {
                    current->next = hop->next;
                }
                hop = hop->next;
            }
            current = current->next;
        }
        return head;
    }
};
