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
    bool isMirror(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (!leftRoot && !rightRoot) {
            return true;
        }
        if (!leftRoot || !rightRoot) {
            return false;
        }
        
        return leftRoot->val == rightRoot->val && isMirror(leftRoot->left, rightRoot->right) && isMirror(leftRoot->right, rightRoot->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }
};