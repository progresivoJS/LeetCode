// Time : O(m * n * N)
// Space : O(m * n)

class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    const int M = 1e9 + 7;
    
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int> > dp(m, vector<int>(n));
        for (int k = 1; k <= N; k++) {
            vector<vector<int> > current(m, vector<int>(n));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    for (int x = 0; x < 4; x++) {
                        int nr = r + dy[x];
                        int nc = c + dx[x];
                        if (nr >= m || nr < 0 || nc >= n || nc < 0) {
                            current[r][c] += 1;
                        }
                        else {
                            current[r][c] += dp[nr][nc];
                        }
                        current[r][c] %= M;
                    }
                }
            }
            dp = current;
        }        
        return dp[i][j];
    }
};
