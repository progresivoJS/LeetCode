// Time : O(n*n)
// Space : O(n)

class Solution {
private:
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int from) {
        int n = M.size();
        visited[from] = true;
        for (int to = 0; to < n; to++) {
            if (M[from][to] && !visited[to]) {
                dfs(M, visited, to);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(M, visited, i);
                count++;
            }
        }
        return count;
    }
};