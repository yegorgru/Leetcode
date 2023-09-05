class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int currMinSecond = INT_MAX;
        int firstProfit = 0;
        int maxProfit = 0;
        vector<int>::iterator maxSecond = prices.begin();
        for (size_t i = 0; i < prices.size(); ++i) {
            auto value = prices[i];
            maxProfit = max(maxProfit, value - currMinSecond + firstProfit);
            currMinSecond = min(currMinSecond, value);
            if (value - currMin > firstProfit) {
                if (!(maxSecond > prices.begin() + i)) {
                    maxSecond = max_element(prices.begin() + i, prices.end());
                    
                }
                if (maxSecond < prices.end()) {
                    maxProfit = max(maxProfit, *maxSecond - currMinSecond + firstProfit);
                }
                firstProfit = value - currMin;
                currMinSecond = value;
            }
            currMin = min(currMin, value);
        }
        return maxProfit;
    }
};
