/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // queue - based bfs version
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            if (q.size() != 0)
                level.push_back(vector<int>());
            while (size-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node == NULL) continue;
                level[depth].push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            depth++;
        }
        
        level.pop_back();
        
        return level;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // recursive level-order traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        traverse(answer, root, 0);
        return answer;
    }
    
private:
    void traverse(vector<vector<int>>& answer, TreeNode* node, int depth) {
        if (node == NULL)
            return;
        if (answer.size() < depth + 1) {
            answer.push_back(vector<int>());
        }
        answer[depth].push_back(node->val);
        traverse(answer, node->left, depth + 1);
        traverse(answer, node->right, depth + 1);
    }
};