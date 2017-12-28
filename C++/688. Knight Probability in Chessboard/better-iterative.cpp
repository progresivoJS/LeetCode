// Time : O(k * n * n)
// Space : O(n * n)

class Solution {
private:
    const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double> > prev(N, vector<double>(N));
        prev[r][c] = 1;
        
        for (int k = 1; k <= K; k++) {
            vector<vector<double> > current(N, vector<double>(N));
            for (int row = 0; row < N; row++) {
                for (int col = 0; col < N; col++) {
                    for (int i = 0; i < 8; i++) {
                        int nr = row + dy[i];
                        int nc = col + dx[i];
                        if (nr >= N || nc >= N || nr < 0 || nc < 0) continue;
                        
                        current[row][col] += prev[nr][nc] / 8;
                    }
                }
            }
            prev = current;
        }
        
        double res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res += prev[i][j];
            }
        }
        
        return res;
    }
};
