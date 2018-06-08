// Time : O(n)
// Space : O(1)

class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        int part = 1;
        while (num != 0) {
            if ((num & 1) == 0) ret += part;
            num = num >> 1;
            part *= 2;
        }
        return ret;
    }
};
