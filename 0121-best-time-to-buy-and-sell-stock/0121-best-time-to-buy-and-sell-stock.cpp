class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < prices[buy]) {
                buy = i;
            }
            if (prices[i] - prices[buy] > profit) {
                profit = prices[i] - prices[buy];
            }
        }
        return profit;
    }
};

