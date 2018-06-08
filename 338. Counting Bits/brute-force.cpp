// Time : O(n)
// Space : O(1)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i = 0; i <= num; i++) {
            int n = i;
            int count = 0;
            while (n) {
                count++;
                n &= (n - 1);
            }
            ret.push_back(count);
        }
        return ret;
    }
};