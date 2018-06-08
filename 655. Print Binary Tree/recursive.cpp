// Time : O(h * 2^h)
// Space : O(h * 2^h)

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
    void traverse(TreeNode* root, vector<vector<string>>& ret, int depth, int lo, int hi) {
        if (!root) return;
        int mid = (lo + hi) / 2;
        ret[depth][mid] = to_string(root->val);
        traverse(root->left, ret, depth + 1, lo, mid - 1);
        traverse(root->right, ret, depth + 1, mid + 1, hi);
    }
    
    int height(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int w = 1;
        for (int i = 0; i < h; i++) {
            w = 2 * w + 1;
        }
        vector<vector<string>> ret(h + 1, vector<string>(w));
        traverse(root, ret, 0, 0, w - 1);
        return ret;
    }
};