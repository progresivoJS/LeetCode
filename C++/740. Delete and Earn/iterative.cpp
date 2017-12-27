// Time : O(Range)
// Space : O(Range)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int RANGE = 10000;
        vector<int> points(RANGE + 1);
        for (int num : nums) {
            points[num] += num;
        }
        for (int i = 2; i < RANGE + 1; i++) {
            points[i] = max(points[i - 2] + points[i], points[i - 1]);
        }
        return points[RANGE];
    }
};
