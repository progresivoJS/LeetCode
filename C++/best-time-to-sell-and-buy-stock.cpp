class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curSum = 0;
        int maxSum = 0;
        
        for (int i = 1 ; i < prices.size(); i++) {
            int a = prices[i] - prices[i - 1];
            curSum = max(a + curSum, a);
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum < 0 ? 0 : maxSum;
    }
};