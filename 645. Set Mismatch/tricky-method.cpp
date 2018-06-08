// Time : O(n)
// Space : O(1)

// Desc : This solution use the fact that the array nums contains only from 1 to n.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret(2);
        for (int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            if (nums[val - 1] < 0) ret[0] = val;
            else nums[val - 1] *= -1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ret[1] = i + 1;
        }
        return ret;
    }
};
