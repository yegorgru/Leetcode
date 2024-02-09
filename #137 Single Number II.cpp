class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::vector<int> sumBits = findSumBits(nums);
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            res <<= 1;
            if (sumBits[i] % 3 == 1) {
                res |= 1;
            }
        }
        return res;
    }

private:
    std::vector<int> findSumBits(const std::vector<int>& nums) {
        std::vector<int> result(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                result[i] += (num >> i) & 1;
            }
        }
        return result;
    }
};
