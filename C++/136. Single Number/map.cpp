// Time : O(n)
// Space : O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        for (const auto& e : map) {
            if (e.second == 1) return e.first;
        }
        return -1;
    }
};
