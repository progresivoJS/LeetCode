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
    int height(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        int gap = abs(height(root->left) - height(root->right));
        if (gap >= 2)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};