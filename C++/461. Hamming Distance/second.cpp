// Time : O(n)
// Space : O(1)

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int diff = x ^ y;
        while (diff) {
            if (diff & 1) count++;
            diff >>= 1;
        }
        return count;
    }
};