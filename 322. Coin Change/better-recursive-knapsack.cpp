// Time : O(n * amount)
// Space : O(amount)

class Solution {
private:
    const int INF = 987654321;
    vector<int> cache;
    
    // coins amount만큼 만들어야할 때, 필요한 동전 수의 최솟값.
    int change(vector<int>& coins, int amount) {
        if (amount < 0) return INF;
        if (amount == 0) return 0;
        
        int& ret = cache[amount];
        if (ret != -1) return ret;
        
        int res = INF;
        for (int coin : coins) {
            res = min(res, 1 + change(coins, amount - coin));
        }
        return ret = res;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        cache = vector<int>(amount + 1, -1);
        int ret = change(coins, amount);
        return ret == INF ? -1 : ret;
    }
};
