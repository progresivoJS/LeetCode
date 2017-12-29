// Time : O(n^2)
// Space : O(n)

class Solution {
private:
    vector<int> cache;
    
    int find(vector<int>& nums, int start) {        
        int& ret = cache[start];
        if (ret != -1) return ret;
        
        int res = 1;
        for (int next = 0; next < start; next++) {
            if (nums[next] < nums[start]) {
                res = max(res, 1 + find(nums, next));
            }
        }
        return ret = res;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        int ret = 0;
        for (int start = 0; start < nums.size(); start++) {
            ret = max(ret, find(nums, start));
        }
        return ret;
    }
};
