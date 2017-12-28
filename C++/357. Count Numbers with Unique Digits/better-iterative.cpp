// Time : O(n)
// Space : O(n)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(n + 1);
        dp[1] = 10;
        dp[2] = 81;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] * (11 - i);
        }
        int sum = 0;
        for (int num : dp) sum += num;
        return sum;
    }
};
