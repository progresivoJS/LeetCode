// Time : O(n)
// Space : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], nums[i] + currentSum);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
