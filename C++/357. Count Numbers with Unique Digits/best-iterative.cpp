// Time : O(1)
// Space : O(1)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ret = 10;
        int base = 9;
        for (int i = 2; i <= n && i <= 10; i++) {
            base = base * (11 - i);
            ret += base;
        }
        return ret;
    }
};
