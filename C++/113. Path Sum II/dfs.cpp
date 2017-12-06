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
    int targetSum;
    void find(vector<vector<int>>& paths, vector<int>& path, TreeNode* root, int currentSum) {
        if (!root) return;
        path.push_back(root->val);
        currentSum += root->val;
        if (!root->left && !root->right && currentSum == targetSum) {
            paths.push_back(path);
        }
        find(paths, path, root->left, currentSum);
        find(paths, path, root->right, currentSum);
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        this->targetSum = sum;
        vector<vector<int>> paths;
        vector<int> path;
        find(paths, path, root, 0);
        return paths;
    }
};