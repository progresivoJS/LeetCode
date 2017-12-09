// Time : O(logn * logn)
// Space : O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = 0;
        TreeNode* traverse = root;
        while (traverse) {
            leftHeight++;
            traverse = traverse->left;
        }
        int rightHeight = 0;
        traverse = root;
        while (traverse) {
            rightHeight++;
            traverse = traverse->right;
        }
        
        if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};