// Time : O(n^2)
// Space : O(n^2)

class Solution {
private:
    vector<int> nums;
    set<vector<int>> ret;
    
    void find(vector<int> current, int start) {
        for (int next = start + 1; next < nums.size(); next++) {
            if (nums[start] <= nums[next]) {
                current.push_back(nums[next]);
                ret.insert(current);
                find(current, next);
                current.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        vector<int> current;
        for (int i = 0; i < nums.size(); i++) {
            current.push_back(nums[i]);
            find(current, i);
            current.pop_back();
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
