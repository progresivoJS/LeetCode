// Time : O(n * newTarget)
// Space : O(n * newTarget)

class Solution {
private:
    vector<vector<int> > cache;
    int knapsack(vector<int>& nums, int start, int target) {
        if (target < 0) return 0;
        if (start == nums.size()) return target == 0;
        
        int& ret = cache[start][target];
        if (ret != -1) return ret;
        
        int res = 0;
        res += (knapsack(nums, start + 1, target) + knapsack(nums, start + 1, target - nums[start]));
        return ret = res;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i : nums) sum += i;
        int newTarget = sum + S;
        if (newTarget & 1 || (newTarget >> 1) > sum) return 0;
        newTarget >>= 1;
        
        cache = vector<vector<int> >(nums.size(), vector<int>(newTarget + 1, -1));
        int ret = knapsack(nums, 0, newTarget);
        return ret;
    }
};
