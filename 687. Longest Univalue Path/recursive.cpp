// Time : from O(nlogn) to O(n*n)
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
    int dfs(TreeNode* root, int val) {
        if (!root || root->val != val) return 0;
        return 1 + max(dfs(root->left, root->val), dfs(root->right, root->val));
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        return max({dfs(root->left, root->val) + dfs(root->right, root->val),longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
    }
};