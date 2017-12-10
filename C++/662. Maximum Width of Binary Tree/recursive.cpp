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
    int dfs(TreeNode* root, int id, int depth, vector<int>& lefts) {
        if (!root) return 0;
        if (depth >= lefts.size()) lefts.push_back(id);
        return max({id - lefts[depth] + 1, dfs(root->left, 2 * id, depth + 1, lefts), dfs(root->right, 2 * id + 1, depth + 1, lefts)});
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        return dfs(root, 1, 0, lefts);
    }
};