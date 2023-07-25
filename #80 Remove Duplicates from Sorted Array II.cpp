class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = nums[0];
        int currentCount = 0;
        size_t batchStart = 0;
        size_t expectedSize = nums.size();
        for (size_t i = 0; i < expectedSize; ++i) {
            int n = nums[i];
            if(n != current) {
                if(currentCount > 2) {
                    copy(nums.begin() + i, nums.end(), nums.begin() + batchStart + 2);
                    batchStart += 2;
                    i = batchStart;
                    expectedSize -= currentCount - 2;
                }
                else {
                    batchStart = i;
                }
                current = n;
                currentCount = 1;
                continue;
            }
            ++currentCount;
        }
        if(currentCount > 2) {
            expectedSize -= currentCount - 2;
        }
        return expectedSize;
    }
};
