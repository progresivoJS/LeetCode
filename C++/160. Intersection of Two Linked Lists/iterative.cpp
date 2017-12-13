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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        bool loopedA = false;
        bool loopedB = false;
        while (ptr1 && ptr2) {
            if (ptr1 == ptr2) return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (!ptr1 && !loopedA) {
                loopedA = true;
                ptr1 = headB;
            }
            if (!ptr2 && !loopedB) {
                loopedB = true;
                ptr2 = headA;
            }
        }
        return nullptr;
    }
};