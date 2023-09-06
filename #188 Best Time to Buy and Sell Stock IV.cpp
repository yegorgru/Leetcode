class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<Extremum> extremums{ {findMinimum(prices, 0), false} };
        while (extremums.back().idx < prices.size() - 1) {
            extremums.push_back({ findMaximum(prices, extremums.back().idx + 1), true});
            extremums.push_back({ findMinimum(prices, extremums.back().idx + 1), false });
        }
        return findMaxProfit(k, 0, extremums, prices);
    }

private:
    struct Extremum {
        size_t idx;
        bool isMax;
    };

private:
    int findMaxProfit(int k, size_t currMinIdx, const vector<Extremum>& extremums, const vector<int>& prices) {
        if (k <= 0 || currMinIdx >= extremums.size() - 1) {
            return 0;
        }
        auto key = make_pair(currMinIdx, k);
        auto found = mProfits.find(key);
        if (found != mProfits.end()) {
            return found->second;
        }
        else {
            int currMaxProfit = findMaxProfit(k, currMinIdx + 2, extremums, prices);
            for (size_t i = currMinIdx + 1; i < extremums.size(); i += 2) {
                currMaxProfit = max(currMaxProfit, findMaxProfit(k - 1, i + 1, extremums, prices) + prices[extremums[i].idx] - prices[extremums[currMinIdx].idx]);
            }
            mProfits[key] = currMaxProfit;
            return currMaxProfit;
        }        
    }

    size_t findMinimum(const vector<int>& prices, size_t currIdx) {
        while (currIdx < prices.size() - 1 && prices[currIdx] >= prices[currIdx + 1]) {
            ++currIdx;
        }
        return currIdx;
    }

    size_t findMaximum(const vector<int>& prices, size_t currIdx) {
        while (currIdx < prices.size() - 1 && prices[currIdx] <= prices[currIdx + 1]) {
            ++currIdx;
        }
        return currIdx;
    }

private:
    map<pair<size_t, int>, int> mProfits; 
};
