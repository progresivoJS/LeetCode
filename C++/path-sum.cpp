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
    bool dfs(TreeNode* node, int currentSum, int targetSum) {
        if (node == NULL)
            return false;
        
        currentSum += node->val;
        if (node->left == NULL && node->right == NULL) {
            if (currentSum == targetSum)
                return true;
            else
                return false;
        }
        
        return dfs(node->left, currentSum, targetSum) || dfs(node->right, currentSum, targetSum);
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
    }
};