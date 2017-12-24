// Time : O(n)
// Space : O(1)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numberOfSubset = 1 << nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < numberOfSubset; i++) {
            vector<int> row;
            int n = i;
            while (n) {
                int one = n ^ (n & (n - 1));
                int index = 0;
                while (one >> 1) {
                    index++;
                    one >>= 1;
                }
                row.push_back(nums[index]);
                n &= (n - 1);
            }
            ret.push_back(row);
        }
        return ret;
    }
};