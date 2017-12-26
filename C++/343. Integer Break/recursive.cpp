// Time : O(n * n)
// Space : O(n)

class Solution {
private:
    vector<int> cache;
    
    int breaker(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        int& ret = cache[n];
        if (ret != -1) return ret;
        
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, max(i * (n-i), i * breaker(n - i)));
        }
        return ret = res;
    }
    
public:
    int integerBreak(int n) {
        cache = vector<int>(n + 1, -1);
        int ret = breaker(n);
        return ret;
    }
};
