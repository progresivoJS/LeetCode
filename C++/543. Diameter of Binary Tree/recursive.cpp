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
    int depthOf(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(depthOf(root->left), depthOf(root->right));
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int result =  depthOf(root->left) + depthOf(root->right);
        result = max(result, diameterOfBinaryTree(root->left));
        result = max(result, diameterOfBinaryTree(root->right));
        return result;
    }
};