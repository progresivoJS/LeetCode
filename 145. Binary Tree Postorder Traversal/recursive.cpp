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
    void traverse(vector<int>& postorder, TreeNode* root) {
        if (!root) return;
        traverse(postorder, root->left);
        traverse(postorder, root->right);
        postorder.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        traverse(postorder, root);
        return postorder;
    }
};