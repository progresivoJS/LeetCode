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
	void traverse(vector<int>& preorder, TreeNode* root) {
		if (!root) return;
		preorder.push_back(root->val);
		traverse(preorder, root->left);
		traverse(preorder, root->right);
	}

public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> preorder;
        traverse(preorder, root);
        return preorder;
    }
};