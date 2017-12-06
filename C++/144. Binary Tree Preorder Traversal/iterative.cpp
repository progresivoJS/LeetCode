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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (!root) return preorder;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            preorder.push_back(current->val);
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
        return preorder;
    }
};