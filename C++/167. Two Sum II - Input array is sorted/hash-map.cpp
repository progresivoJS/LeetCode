// Time : O(n)
// Space : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++) {
            if (map.find(target - numbers[i]) != map.end()) {
                return vector<int> {map[target - numbers[i]] + 1, i + 1};
            }
            else {
                map.insert(make_pair(numbers[i], i));
            }
        }
        return vector<int>();
    }
};
