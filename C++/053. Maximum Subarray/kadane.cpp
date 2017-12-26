// Time : O(n)
// Space : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            maxSum = max(currentSum, maxSum);
            currentSum = max(currentSum, 0);
        }
        
        return maxSum;
    }
};
