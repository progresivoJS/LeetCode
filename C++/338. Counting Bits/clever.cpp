// Time : O(N)
// Space : O(1)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            ret[i] = ret[i & (i - 1)] + 1;
            // ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
};