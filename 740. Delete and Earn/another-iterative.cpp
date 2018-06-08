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
        
        int i = 0;
        int e = 0;
        for (int k = 0; k < RANGE + 1; k++) {
            int tmp = e + points[k];
            e = max(i, e);
            i = tmp;
        }
        return max(i, e);
    }
};
