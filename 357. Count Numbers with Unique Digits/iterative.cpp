// Time : O(n^2)
// Space : O(n)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 9;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = 9 * pow(10, i - 1);
            for (int j = 1; j <= i - 1; j++) {
                dp[i] -= dp[j] * j * pow(10, i - j - 1);
            }
        }
        
        int sum = 0;
        for (int i = 0; i <= n; i++) sum += dp[i];
        return sum;
    }
};
