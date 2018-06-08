// Time : O(n)
// Space : O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int i = 0;
        int e = 0;
        for (int k = 0; k < nums.size(); k++) {
            int tmp = nums[k] + e;
            e = max(i, e);
            i = tmp;
        }
        return max(i, e);
    }
};
