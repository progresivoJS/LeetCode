// Time : O(n)
// Space : O(h)
// a sort of postorder.

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
    int depthOf(TreeNode* root, int& diameter) {
        if (!root) return 0;
        int left = depthOf(root->left, diameter);
        int right = depthOf(root->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int diameter = 0;
        depthOf(root, diameter);
        return diameter;
    }
};