// Time : O(n * sqrt(n))
// Space : O(n)

class Solution {
private:
    vector<int> cache;
    const int INF = 987654321;
    
    // n을 만들기 위해 필요한 square numbers의 최솟값.
    int count(int n) {
        if (n == 0) return 0;
        if (n < 0) return INF;
        
        int& ret = cache[n];
        if (ret != -1) return ret;
        
        int res = INF;
        int range = (int)sqrt(n);
        
        for (int i = 1; i <= range; i++) {
            res = min(res, 1 + count(n - i * i));
        }
        
        return ret = res;
    }
    
public:
    
    int numSquares(int n) {
        cache = vector<int>(n + 1, -1);
        return count(n);
    }
};
