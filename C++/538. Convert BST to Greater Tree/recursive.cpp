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
    void traverse(TreeNode* root, int& pre_sum) {
        if (!root) return;
        traverse(root->right, pre_sum);
        root->val += pre_sum;
        pre_sum = root->val;
        traverse(root->left, pre_sum);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int pre_sum = 0;
        traverse(root, pre_sum);
        return root;
    }
};