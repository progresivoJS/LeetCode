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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->right;
            }
            
            p = s.top();
            s.pop();
            if (pre) p->val += pre->val;
            pre = p;
            p = p->left;
        }
        return root;
    }
};