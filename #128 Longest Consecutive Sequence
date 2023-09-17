class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int curr = 1;
        for(size_t i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i - 1];
            if(diff == 1) {
                ++curr;
            }
            else if(diff != 0) {
                longest = max(longest, curr);
                curr = 1;
            }
        }
        longest = max(longest, curr);
        return longest;
    }
};
