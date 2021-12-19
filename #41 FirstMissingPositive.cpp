//First missing positive

//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> v(nums.size() + 1, -1);
        for(const auto i : nums) {
            if(i > 0 && i <= nums.size()) {
                v[i] = 1;
            }
        }
        for(size_t i = 1; i <= nums.size(); i++) {
            if(v[i] == -1) {
                return i;
            }
        }
        return nums.size() + 1;
    }
};
