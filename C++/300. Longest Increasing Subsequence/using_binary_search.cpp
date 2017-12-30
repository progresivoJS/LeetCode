// Time : O(nlogn)
// Space : O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            int lo = 0;
            int hi = tails.size();
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (tails[mid] < num) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            if (lo == tails.size()) tails.push_back(num);
            else tails[lo] = num;
        }
        return tails.size();
    }
};
