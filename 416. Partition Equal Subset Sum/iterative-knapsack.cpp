// Time : O(n * target)
// Space : O(n * target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int> > dp = vector<vector<int> >(nums.size() + 1, vector<int>(target + 1, 0));
        dp[0][0] = true;
        
        for (int i = 1; i < nums.size() + 1; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < target + 1; i++) {
            dp[0][i] = 0;
        }
        
        // dp[i][j] means whether the specific sum j can be gotten from the first i numbers.
        for (int i = 1; i < nums.size() + 1; i++) {
            for (int j = 1; j < target + 1; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }
        
        return dp[nums.size()][target];
    }
};
