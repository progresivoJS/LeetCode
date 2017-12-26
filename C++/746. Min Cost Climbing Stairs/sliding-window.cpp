// Time : O(n)
// Space : O(1)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i < n; i++) {
            int c = cost[i] + min(a, b);
            a = b;
            b = c;
        }
        return min(a, b);
    }
};
