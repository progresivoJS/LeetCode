// Time : O(n * target)
// Space : O(n * target)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) sum += num;
        int target = (S + sum);
        if (target & 1 || (target >> 1) > sum) return 0;
        target >>= 1;
        
        vector<vector<int> > dp(nums.size() + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[nums.size()][target];
    }
};
