// Time : O(n), n is the number of the 1 in given n.
// Space : O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
