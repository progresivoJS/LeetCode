// Time : O(n)
// Space : O(1)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool check = n & 1;
        n = n >> 1;
        while (n != 0) {
            if (!((n & 1)^check)) return false;
            check = n & 1;
            n = n >> 1;
        }
        return true;
    }
};
