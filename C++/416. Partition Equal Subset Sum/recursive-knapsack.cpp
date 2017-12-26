// Time : O(n * sum/2)
// Space : O(n * sum/2)

class Solution {
private:
    vector<vector<int>> cache;
    bool partition(vector<int>& nums, int start, int target) {
        if (target < 0) return false;
        if (start == nums.size()) return target == 0;
        
        int& ret = cache[start][target];
        if (ret != -1) return ret;
        
        bool res = partition(nums, start + 1, target - nums[start]) || partition(nums, start + 1, target);
        return ret = res ? 1 : 0;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        cache = vector<vector<int> >(nums.size(), vector<int>(target + 1, -1));
        bool ret = partition(nums, 0, target);
        return ret;
    }
};
