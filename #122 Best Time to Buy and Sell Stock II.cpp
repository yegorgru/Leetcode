class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        size_t currMin = findMinimum(prices, 0);
        while(currMin < prices.size() - 1) {
            size_t currMax = findMaximum(prices, currMin + 1);
            profit += prices[currMax] - prices[currMin];
            currMin = findMinimum(prices, currMax + 1);
        }
        return profit;
    }
    
private:
    size_t findMinimum(const vector<int>& prices, size_t currIdx) {
        while(currIdx < prices.size() - 1 && prices[currIdx] >= prices[currIdx + 1]) {
            ++currIdx;
        }
        return currIdx;
    }
    
    size_t findMaximum(const vector<int>& prices, size_t currIdx) {
        while(currIdx < prices.size() - 1 && prices[currIdx] <= prices[currIdx + 1]) {
            ++currIdx;
        }
        return currIdx;
    }
};
