// Time : O(n)
// Space : O(1)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool check = n & 1;
        n = n >> 1;
        while (n != 0) {
            bool current = n & 1;
            if (current == check) return false;
            check = current;
            n = n >> 1;
        }
        return true;
    }
};
