// Time : O(logn)
// Space : O(1)

class Solution {
private:
    // predicate : mid * mid >= num
    bool p(int num, int mid) {
        return mid >= num/mid;
    }
public:
    bool isPerfectSquare(int num) {
        int lo = 1;
        int hi = num;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (p(num, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        
        if (lo * lo == num) return true;
        else return false;
    }
};
