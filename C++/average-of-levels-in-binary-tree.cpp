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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> levelMap;
        traverse(levelMap, root, 0);
        
        vector<double> answer;
        for (int i = 0; i < levelMap.size(); i++) {
            long long sum = 0;
            for (int j = 0; j < levelMap[i].size(); j++) {
                sum += levelMap[i][j];
            }
            answer.push_back((double)sum/levelMap[i].size());
        }
        return answer;
    }
private:
    void traverse(vector<vector<int>>& levelMap, TreeNode* node, int depth) {
        if (!node)
            return;
        if (levelMap.size() < depth + 1)
            levelMap.push_back(vector<int>());
        levelMap[depth].push_back(node->val);
        traverse(levelMap, node->left, depth + 1);
        traverse(levelMap, node->right, depth + 1);
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
 // version 2
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<double> ans;
        
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
            
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            
            ans.push_back(sum/size);
        }
        
        return ans;
    }
};