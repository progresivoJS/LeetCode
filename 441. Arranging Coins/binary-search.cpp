// Time : O(logn)
// Space : O(1)

class Solution {
private:
    // predicate : sum of 1 ~ mid > n
    bool p(long mid, int n) {
        long sum = (mid * (mid + 1)) / 2;
        return sum > n;
    }
    
public:
    int arrangeCoins(int n) {
        long lo = 0;
        long hi = n;
        while (lo < hi) {
            long mid = lo + (hi - lo + 1) / 2;
            if (p(mid, n)) {
                hi = mid - 1;
            }
            else {
                lo = mid;
            }
        }
        return lo;
    }
};
