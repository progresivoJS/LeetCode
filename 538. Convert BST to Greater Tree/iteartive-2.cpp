// Time : O(n)
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
    void traverse(TreeNode* root, TreeNode*& pre) {
        if (!root) return;
        traverse(root->right, pre);
        if (pre) root->val += pre->val;
        pre = root;
        traverse(root->left, pre);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        traverse(root, pre);
        return root;
    }
};