// Time : O(logn)
// Space : O(1)

class Solution {
private:
    // predicate : mid * mid > target?
    bool p(long mid, int target) {
        long square = mid * mid;
        return square > target;
    }
    
public:
    int mySqrt(int x) {
        long lo = 0;
        long hi = x;
        while (lo < hi) {
            long mid = lo + (hi - lo + 1) / 2;
            if (p(mid, x)) {
                hi = mid - 1;
            }
            else {
                lo = mid;
            }
        }
        return lo;
    }
};
