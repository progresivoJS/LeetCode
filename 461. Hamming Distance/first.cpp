// Time : O(n)
// Space : O(1)

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x || y) {
            if ((x ^ y) & 1) count++;
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};