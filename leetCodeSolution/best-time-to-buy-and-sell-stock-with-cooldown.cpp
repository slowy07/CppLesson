class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> buy(2), sell(2), coolDown(2);
        buy[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            buy[i % 2] = max(buy[(i - 1) % 2], coolDown[(i - 1) % 2] - prices[i]);
            sell[i % 2] = buy[(i - 1) % 2] + prices[i];
            coolDown[i % 2] = max(coolDown[(i - 1) % 2], sell[(i - 1) % 2]);
        }
        return max(coolDown[(prices.size() - 1) % 2], sell[(prices.size() - 1) % 2]);
    }
};
