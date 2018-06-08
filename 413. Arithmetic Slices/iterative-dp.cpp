// Time : O(n)
// Space : O(n)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n);
        if (n <= 2) return 0;
        dp[0] = dp[1] = 0;
        dp[2] = (A[1] - A[0] == A[2] - A[1]) ? 1 : 0;
        int ret = dp[2];
        for (int i = 3; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            ret += dp[i];
        }
        return ret;
    }
};
