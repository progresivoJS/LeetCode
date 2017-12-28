// Time : O(k * n * n)
// Space : O(k * n * n)

class Solution {
private:
    const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<vector<vector<double> > > cache;
    int n;
    int count = 0;
    
    double jump(int remain, int r, int c) {
        if (r >= n || r < 0 || c >= n || c < 0) return 0;
        if (remain == 0) return 1;
        
        double& ret = cache[remain][r][c];
        if (ret != -1) return ret;
        
        double res = 0;
        for (int i = 0; i < 8; i++) {
            res += jump(remain - 1, r + dy[i], c + dx[i]) / 8;
        }
        return ret = res;
    }
    
public:
    double knightProbability(int N, int K, int r, int c) {
        n = N;
        cache = vector<vector<vector<double> > >(K + 1, vector<vector<double> >(N, vector<double>(N, -1)));
        double res = jump(K, r, c);
        return res;
    }
};
