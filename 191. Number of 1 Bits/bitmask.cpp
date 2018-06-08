// Time : O(n)
// Space : O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int p = 1;
        int count = 0;
        while (n != 0) {
            if (n & p == 1) count++;
            n = n >> 1;
        }
        return count;
    }
};
