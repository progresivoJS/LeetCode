// Time : O(n)
// Space : O(1)

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return n == 1 ? a : b;
    }
};
