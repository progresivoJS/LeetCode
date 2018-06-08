// Time : O(n)
// Space : O(1)

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* queue = root;
        while (queue) {
            TreeLinkNode* level = new TreeLinkNode(0);
            TreeLinkNode* current = level;
            while (queue) {
                if (queue->left) {
                    current->next = queue->left;
                    current = current->next;
                }
                if (queue->right) {
                    current->next = queue->right;
                    current = current->next;
                }
                queue = queue->next;
            }
            queue = level->next;
            
            delete level;
        }
    }
};
