// Time : O(n^(3/2))
// Space : O(n)

class Solution {
private:
    const int INF = 987654321;
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            int j = 1;
            while (i - j * j >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
                j++;
            }
        }
        return dp[n];
    }
};
