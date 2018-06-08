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
    int helper(TreeNode* root, int sum) {
        if (!root)
            return 0;
        sum += root->val;
        if (!root->left && !root->right)
            return val;
        return helper(root->left, sum * 10) + helper(root->right, sum * 10);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};
