// Time : O(n)
// Space : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            int res = numbers[lo] + numbers[hi];
            if (res < target) {
                lo++;
            }
            else if (res > target) {
                hi--;
            }
            else {
                return vector<int> {lo + 1, hi + 1};
            }
        }
        return vector<int>();
    }
};
