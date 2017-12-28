// Time : O(m * n * N)
// Space : O(m * n * N)

class Solution {
private:
    const int M = 1000000007;
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    vector<vector<vector<int> > > cache;
    int m, n;
    
    int traverse(int r, int c, int remain) {
        if (r >= m || r < 0 || c >= n || c < 0) {
            if (remain == 0) return 1;
            else return 0;
        }
        if (remain == 0) return 0;
        
        int& ret = cache[r][c][remain];
        if (ret != -1) return ret;
        
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            res += traverse(nr, nc, remain - 1);
            res %= M;
        }
        
        return ret = res;
    }
    
public:
    int findPaths(int m, int n, int N, int i, int j) {
        cache = vector<vector<vector<int> > >(m, vector<vector<int> >(n, vector<int>(N + 1, -1)));
        this->m = m;
        this->n = n;
        int ret = 0;
        for (int n = 1; n <= N; n++) {
            ret += traverse(i, j, n);
            ret %= M;
        }
        return ret;
    }
};
