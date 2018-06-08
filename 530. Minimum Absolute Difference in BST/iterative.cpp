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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        int minAbs = INT_MAX;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if (pre) minAbs = min(minAbs, p->val - pre->val);
            s.pop();
            pre = p;
            p = p->right;
        }
        return minAbs;
    }
};