class Solution {
private:
    int searchWay(vector<int>& nums, int start, int target) {
        if (start == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        
        int res = 0;
        res += searchWay(nums, start + 1, target - nums[start]);
        res += searchWay(nums, start + 1, target + nums[start]);
        return res;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int res = searchWay(nums, 0, S);
        return res;
    }
};
