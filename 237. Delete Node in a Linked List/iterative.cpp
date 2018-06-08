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
    void deleteNode(ListNode* node) {
        while (node) {
            if (node->next) {
                node->val = node->next->val;
            }
            if (node->next && !node->next->next) {
                node->next = nullptr;
            }
            node = node->next;
        }
    }
};