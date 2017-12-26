// Time : O(n)
// Space : O(n)

class Solution {
public:
    int climb(int* cache, int n) {
        if (n <= 1) return 1;
        
        int& ret = cache[n];
        if (ret != -1)
            return ret;
        
        int result = climb(cache, n - 1) + climb(cache, n - 2);
        return ret = result;
    }
    
    int climbStairs(int n) {
        int* cache = new int[n + 1];
        memset(cache, -1, sizeof(int) * (n + 1));
        int ret = climb(cache, n);
        delete[] cache;
        return ret;
    }
};
