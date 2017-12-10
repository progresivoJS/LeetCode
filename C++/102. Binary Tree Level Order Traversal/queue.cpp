// Time : O(n)
// Space : O(n)

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            if (q.size() != 0)
                level.push_back(vector<int>());
            while (size-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) continue;
                level[depth].push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            depth++;
        }
        
        level.pop_back();
        
        return level;
    }
};