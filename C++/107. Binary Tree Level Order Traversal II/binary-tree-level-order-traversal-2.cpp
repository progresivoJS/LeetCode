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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        traverse(answer, root, 0);
        return vector<vector<int>>(answer.rbegin(), answer.rend());
    }
private:
    void traverse(vector<vector<int>>& answer, TreeNode* node, int depth) {
        if (node == NULL)
            return;
        if (answer.size() < depth + 1)
            answer.push_back(vector<int>());
        traverse(answer, node->left, depth + 1);
        traverse(answer, node->right, depth + 1);
        answer[depth].push_back(node->val);
    }
};