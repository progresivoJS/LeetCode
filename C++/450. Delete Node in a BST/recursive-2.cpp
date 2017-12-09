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
    TreeNode* findMax(TreeNode* root) {
        if (!root->right) return root;
        return findMax(root->right);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        int cmp = key - root->val;
        if (cmp < 0) {
            root->left = deleteNode(root->left, key);
        }
        else if (cmp > 0) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* maxNode = findMax(root->left);
            root->val = maxNode->val;
            root->left = deleteNode(root->left, maxNode->val);
        }
        
        return root;
    }
};