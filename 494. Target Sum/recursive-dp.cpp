// Time : O(n * s) + hash cost.
// Space : O(n)

class Solution {
private:
    unordered_map<string, int> map;
    int searchWay(vector<int>& nums, int start, int target) {
        if (start == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        
        string p = to_string(start) + "->" + to_string(target);
        if (map.find(p) != map.end()) {
            return map[p];
        }
        
        int res = 0;
        res += searchWay(nums, start + 1, target - nums[start]);
        res += searchWay(nums, start + 1, target + nums[start]);
        
        map.insert({p, res});
        return res;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int res = searchWay(nums, 0, S);
        return res;
    }
};
