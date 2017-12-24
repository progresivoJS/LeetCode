// Time : O(n)
// Space : O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & mask) count++;
                if (count > nums.size() / 2) {
                    ret |= mask;
                    break;
                }
            }
            mask <<= 1;
        }
        return ret;
    }
};