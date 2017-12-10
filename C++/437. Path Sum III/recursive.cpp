// Time : from O(nlgn) to O(n^2)
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
    int sumUp(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return (root->val == targetSum) + sumUp(root->left, targetSum - root->val) + sumUp(root->right, targetSum - root->val);
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};