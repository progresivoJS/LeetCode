// Time : O(logn)
// Space : O(1)

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (guess(mid) <= 0) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
