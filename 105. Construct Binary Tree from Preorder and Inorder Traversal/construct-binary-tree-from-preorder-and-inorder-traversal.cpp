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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[ps]);
        
        int pos = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == root->val) {
                pos = i;
                break;
            }
        }
        
        root->left = helper(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        root->right = helper(preorder, inorder, ps + pos - is + 1, pe, pos + 1, ie);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};