// Time : O(n * target)
// Space : O(target)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) sum += num;
        int target = (S + sum);
        if (target & 1 || (target >> 1) > sum) return 0;
        target >>= 1;
        
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[target];
    }
};
