// Time : O(m * n * N)
// Space : O(m * n * N)

class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    const int M = 1e9 + 7;
    
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int> > > dp(N + 1, vector<vector<int> >(m, vector<int>(n)));
        
        for (int k = 1; k <= N; k++) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    for (int x = 0; x < 4; x++) {
                        int nr = r + dy[x];
                        int nc = c + dx[x];
                        if (nr >= m || nr < 0 || nc >= n || nc < 0) {
                            dp[k][r][c] += 1;
                        }
                        else {
                            dp[k][r][c] += dp[k - 1][nr][nc];
                        }
                        
                        dp[k][r][c] %= M;
                    }
                }
            }
        }
        
        return dp[N][i][j];
    }
};
