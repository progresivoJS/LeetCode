// Time : O(n)
// Space : O(n)

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int width = 0;
        while (!q.empty()) {
            int size = q.size();
            int leftId = q.front().second;
            while (size-- > 0) {
                TreeNode* node = q.front().first;
                int id = q.front().second;
                q.pop();
                width = max(width, id - leftId + 1);
                if (node->left)
                    q.push(make_pair(node->left, 2 * id));
                if (node->right)
                    q.push(make_pair(node->right, 2 * id + 1));
            }
        }
        return width;
    }
};