// Time : O(nlogn)
// Space : O(1)

class Solution {
private:
    bool p(vector<int>& nums, int mid) {
        int count = 0;
        for (int num : nums) {
            if (num <= mid) count++;
        }
        return count > mid;
    }
    
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (p(nums, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
