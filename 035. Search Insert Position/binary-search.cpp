// Time : O(logn)
// Space : O(1)

class Solution {
private:
    // predicate : nums[mid] >= target;
    bool p(vector<int>& nums, int mid, int target) {
        return nums[mid] >= target;
    }
    
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (p(nums, mid, target)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
