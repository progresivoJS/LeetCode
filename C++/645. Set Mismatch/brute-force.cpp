// Time : O(n)
// Space : O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        vector<bool> marked(nums.size(), false);
        for (int i = 0; i < n; i++) {
            if (marked[nums[i]]) {
                ret.push_back(nums[i]);
            }
            else {
                marked[nums[i]] = true;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (!marked[i]) {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};
