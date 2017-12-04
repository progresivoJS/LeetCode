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