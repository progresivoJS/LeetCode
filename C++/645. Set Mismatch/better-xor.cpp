// Time : O(n)
// Space : O(1)

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
        
        for (int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            if (nums[val - 1] < 0) {
                ret[0] = val;
                break;
            }
            else {
                nums[val - 1] *= -1;
            }
        }
        
        ret[1] = res ^ ret[0];
        return ret;
    }
};
