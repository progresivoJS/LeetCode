// Time : O(n)
// Space : O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret(2);
        
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= (i + 1);
            res ^= nums[i];
        }
        
        // res = a ^ b;
        // we have to find a, b.
        
        vector<int> count(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            if (++count[nums[i]] == 2) {
                ret[0] = nums[i];
            }
        }
        
        ret[1] = res ^ ret[0];
        return ret;
    }
};
