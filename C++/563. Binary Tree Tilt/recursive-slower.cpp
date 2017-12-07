// Time : O(nlogn?)
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
    int sumOf(TreeNode* root) {
        if (!root) return 0;
        return sumOf(root->left) + sumOf(root->right) + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int tilt = abs(sumOf(root->left) - sumOf(root->right));
        return tilt + findTilt(root->left) + findTilt(root->right);
    }
};