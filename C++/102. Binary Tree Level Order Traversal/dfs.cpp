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
    void dfs(TreeNode* root, int depth, vector<vector<int>>& levelOrder) {
        if (!root) return;
        if (depth >= levelOrder.size()) levelOrder.push_back(vector<int>());
        levelOrder[depth].push_back(root->val);
        dfs(root->left, depth + 1, levelOrder);
        dfs(root->right, depth + 1, levelOrder);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder;
        dfs(root, 0, levelOrder);
        return levelOrder;
    }
};