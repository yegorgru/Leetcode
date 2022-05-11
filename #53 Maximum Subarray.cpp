class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
