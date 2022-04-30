class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        long long leftSum = 0;
        int leftNumsCounter = 0;
        long long rightSum = std::accumulate(nums.begin(), nums.end(), 0ll);
        int answer = 0;
        long long answerDifference = std::numeric_limits<long long>::max();
        for(size_t i = 0; i < nums.size(); i++) {
            leftSum += nums[i];
            ++leftNumsCounter;
            rightSum -= nums[i];
            long long newDifference = leftNumsCounter != nums.size() ? std::llabs(leftSum / leftNumsCounter - rightSum / (nums.size() - leftNumsCounter)) : leftSum / leftNumsCounter;
            if(answerDifference > newDifference) {
                answerDifference = newDifference;
                answer = i;
            }
        }
        return answer;
    }
};
