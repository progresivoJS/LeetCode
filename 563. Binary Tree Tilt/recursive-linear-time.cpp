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
    int sumOf(TreeNode* root, int& ret) {
        if (!root) return 0;
        int left = sumOf(root->left, ret);
        int right = sumOf(root->right, ret);
        ret += abs(left - right);
        return left + right + root->val;
    }
    
public:
    int findTilt(TreeNode* root) {
        int ret = 0;
        sumOf(root, ret);
        return ret;
    }
};