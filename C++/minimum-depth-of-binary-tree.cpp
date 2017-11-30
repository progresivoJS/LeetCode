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
    int dfs(TreeNode* node) {
        if (node == NULL)
            return 0;
        
        if (node->right != NULL && node->left != NULL)
            return 1 + min(minDepth(node->left), minDepth(node->right));
        else
            return 1 + max(minDepth(node->left), minDepth(node->right));
    }
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};