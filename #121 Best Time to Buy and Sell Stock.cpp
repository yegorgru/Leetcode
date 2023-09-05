class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int maxProfit = 0;
        for(size_t i = 1; i < prices.size(); ++i) {
            if(prices[i] < currMin) {
                currMin = prices[i];
            }
            else {
                maxProfit = max(maxProfit, prices[i] - currMin);
            }
        }
        return maxProfit;
    }
};
