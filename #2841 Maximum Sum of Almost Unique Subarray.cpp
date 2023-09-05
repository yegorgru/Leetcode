class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        map<int, int> currCounts;
        long long maxSum = 0;
        long long currSum = 0;
        for(size_t i = 0; i < k; ++i) {
            ++currCounts[nums[i]];
            currSum += nums[i];
        }
        if(currCounts.size() >= m) {
            maxSum = currSum;
        }
        for(size_t i = k; i < nums.size(); ++i) {
            int toRemove = nums[i-k];
            auto found = currCounts.find(toRemove);
            if(found->second == 1) {
                currCounts.erase(found);
            }
            else {
                --(found->second);
            }
            ++currCounts[nums[i]];
            currSum += nums[i];
            currSum -= toRemove;
            if(currCounts.size() >= m) {
                maxSum = max(currSum, maxSum);
            }
        }
        return maxSum;
    }
};
