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
    string tree2str(TreeNode* t) {
        string s;
        if (!t) return s;
        s += to_string(t->val);
        if (t->left || t->right) {
            s += '(';
            s += tree2str(t->left);
            s += ')';
        }
        if (t->right) {
            s += '(';
            s += tree2str(t->right);
            s += ')';
        }
        return s;
    }
};