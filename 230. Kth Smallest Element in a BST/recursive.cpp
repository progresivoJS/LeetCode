// Time : O(n) I proved it.
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
private:
    int sizeOf(TreeNode* root) {
        if (!root) return 0;
        return 1 + sizeOf(root->left) + sizeOf(root->right);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int lsize = sizeOf(root->left);
        if (lsize + 1 == k) return root->val;
        else if (lsize + 1 > k) return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k - lsize - 1);
    }
};