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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) {
            return NULL;
        }
        
        int val = postorder[pe];
        TreeNode* root = new TreeNode(val);
        
        int pos = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == val) {
                pos = i;
                break;
            }
        }
        
        root->left = helper(inorder, postorder, ps, ps + pos - is - 1, is, pos - 1);
        root->right = helper(inorder, postorder, ps + pos - is, pe - 1, pos + 1, ie);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};