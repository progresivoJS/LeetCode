// Time : O(n) + plus more.. because insert function.
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
    void dfs(TreeNode* root, int depth, vector<vector<int>>& zigzag) {
        if (!root) return;
        if (depth >= zigzag.size()) zigzag.push_back(vector<int>());
        if (depth % 2 == 0)
            zigzag[depth].push_back(root->val);
        else
            zigzag[depth].insert(zigzag[depth].begin(), root->val);
        dfs(root->left, depth + 1, zigzag);
        dfs(root->right, depth + 1, zigzag);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        dfs(root, 0, zigzag);
        return zigzag;
    }
};