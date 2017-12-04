/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // version 1
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* store = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        TreeNode* cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = store;
    }
};

// version 2 -> reverse preorder
class Solution {
private:
    TreeNode* prev;
    
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
