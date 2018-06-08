// Time : from O(n) to O(n^2) because the time complexity of the find function
// takes from constant time to linear time.
// Space : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int findingVal = target - nums[i];
            if (map.find(findingVal) != map.end()) {
                ret.push_back(map[findingVal]);
                ret.push_back(i);
                return ret;
            }
            else {
                map[nums[i]] = i;
            }
        }
        return ret;
    }
};