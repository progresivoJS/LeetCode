// Time : O(n)
// Space : O(1)

class Solution {
private:
    int n;
    vector<int> cache;
    const int INF = 987654321;
    int rob(vector<int>& nums, int index) {
        if (index == n)
            return 0;
        if (index > n)
            return -INF;
        int &ret = cache[index];
        if (ret != -1)
            return ret;
        
        int result = nums[index];
        result = max(result, nums[index] + rob(nums, index + 2));
        result = max(result, nums[index] + rob(nums, index + 3));
        return ret = result;
    }
    
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        cache = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cache[i] = -1;
        }
        
        int result = 0;
        result = max(result, rob(nums, 0));
        result = max(result, rob(nums, 1));
        
        return result;
    }
};
