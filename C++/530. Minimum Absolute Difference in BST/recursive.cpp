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
    void dfs(TreeNode* root, TreeNode*& pre, int& minAbs) {
        if (!root) return;
        dfs(root->left, pre, minAbs);
        if (pre) minAbs = min(minAbs, root->val - pre->val);
        pre = root;
        dfs(root->right, pre, minAbs);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        int minAbs = INT_MAX;
        TreeNode* pre = nullptr;
        dfs(root, pre, minAbs);
        return minAbs;
    }
};