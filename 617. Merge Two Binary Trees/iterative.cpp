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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        stack<TreeNode*> s1, s2;
        s1.push(t1);
        s2.push(t2);
        while (!s1.empty()) {
            TreeNode* first = s1.top();
            TreeNode* second = s2.top();
            s1.pop();
            s2.pop();
            first->val += second->val;
            if (!first->right)
                first->right = second->right;
            else if (first->right && second->right) {
                s1.push(first->right);
                s2.push(second->right);
            }
            if (!first->left)
                first->left = second->left;
            else if (first->left && second->left) {
                s1.push(first->left);
                s2.push(second->left);
            }
        }
        return t1;
    }
};