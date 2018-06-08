// Time : O(K * n * n)
// Space : O(K * n * n)

class Solution {
private:
    const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
public:
    double knightProbability(int N, int K, int r, int c) {
        
        // dp[k][i][j] = k번 jump를 하고나서, i, j에 도착할 확률.
        vector<vector<vector<double> > > dp(K + 1, vector<vector<double> >(N, vector<double>(N)));
        dp[0][r][c] = 1;
        
        for (int k = 1; k <= K; k++) {
            for (int row = 0; row < N; row++) {
                for (int col = 0; col < N; col++) {
                    for (int i = 0; i < 8; i++) {
                        int nr = row + dy[i];
                        int nc = col + dx[i];
                        if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;
                        dp[k][row][col] += dp[k - 1][nr][nc] / 8;
                    }
                }
            }
        }
        
        double res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res += dp[K][i][j];
            }
        }
        
        return res;
    }
};
