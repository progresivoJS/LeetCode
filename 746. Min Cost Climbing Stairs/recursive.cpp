// Time : O(n)
// Space : O(n)

class Solution {
private:
    vector<int> cache;
    int climb(vector<int>& cost, int index) {
        if (index == cost.size()) {
            return 0;
        }
        if (index > cost.size()) {
            return INT_MAX;
        }
        
        int& ret = cache[index];
        if (ret != -1) {
            return ret;
        }
        
        int minimum = cost[index] + min(climb(cost, index + 1), climb(cost, index + 2));
        return ret = minimum; 
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cache = vector<int>(n, -1);
        int ret = min(climb(cost, 0), climb(cost, 1));
        return ret;
    }
};
