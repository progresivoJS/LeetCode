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
private:
    void helper(vector<string>& paths, vector<int>& path, TreeNode* root) {
        path.push_back(root->val);
        
        if (!root->left && !root->right) {
            string s;
            for (int i = 0; i < path.size() - 1; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            paths.push_back(s);
            path.pop_back();
            return;
        }
        
        if (root->left)
            helper(paths, path, root->left);
        if (root->right)
            helper(paths, path, root->right);
        
        path.pop_back();
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return vector<string>();
        
        vector<string> paths;
        vector<int> path;
        helper(paths, path, root);
        return paths;
    }
};

// version 2
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
    void helper(vector<string>& paths, string s, TreeNode* root) {
        if (!root->left && !root->right) {
            paths.push_back(s);
            return;
        }
        
        if (root->left)
            helper(paths, s + "->" + to_string(root->left->val), root->left);
        if (root->right)
            helper(paths, s + "->" + to_string(root->right->val), root->right);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        helper(paths, to_string(root->val), root);
        return paths;
    }
};