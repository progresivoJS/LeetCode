// Time : O(n * 2^n)
// Space : O(1)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int pow = 1 << size;
        vector<vector<int> > ret(pow);
        for (int i = 0; i < pow; i++) {
            for (int j = 0; j < size; j++) {
                if ((1 << j) & i) ret[i].push_back(nums[j]);
            }
        }
        return ret;
    }
};