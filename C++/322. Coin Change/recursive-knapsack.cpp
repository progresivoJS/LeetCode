// Time : O(n * n * amount)
// Space : O(n * amount)

class Solution {
private:
    const int INF = 987654321;
    vector<vector<int> > cache;
    
    // start부터 amount만큼 만들어야할 때, 필요한 동전 수의 최솟값.
    int change(vector<int>& coins, int start, int amount) {
        if (amount < 0) return INF;
        if (amount == 0) return 0;
        
        int& ret = cache[start][amount];
        if (ret != -1) return ret;
        
        int res = INF;
        for (int next = start; next < coins.size(); next++) {
            res = min(res, 1 + change(coins, next, amount - coins[next]));
        }
        return ret = res;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        cache = vector<vector<int> >(coins.size(), vector<int>(amount + 1, -1));
        int ret = change(coins, 0, amount);
        return ret == INF ? -1 : ret;
    }
};
