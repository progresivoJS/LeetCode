// Time : O(n)
// Space : O(1)

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
    void find(vector<vector<int>>& paths, vector<int>& path, TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            paths.push_back(path);
        }
        find(paths, path, root->left, sum - root->val);
        find(paths, path, root->right, sum - root->val);
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        find(paths, path, root, sum);
        return paths;
    }
};