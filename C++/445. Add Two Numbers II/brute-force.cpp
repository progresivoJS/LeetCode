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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reverseL1 = reverse(l1);
        ListNode* reverseL2 = reverse(l2);
        
        int up = 0;
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        
        while (reverseL1 || reverseL2 || up) {
            int a = reverseL1 ? reverseL1->val : 0;
            int b = reverseL2 ? reverseL2->val : 0;
            int s = a + b + up;
            current->next = new ListNode(s % 10);
            current = current->next;
            up = s / 10;
            reverseL1 = reverseL1 ? reverseL1->next : nullptr;
            reverseL2 = reverseL2 ? reverseL2->next : nullptr;
        }
        
        return reverse(head->next);
    }
};
