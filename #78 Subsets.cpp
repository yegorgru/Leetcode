class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets(nums, nums.size() - 1);
    }

private:
    vector<vector<int>> subsets(vector<int>& nums, size_t idx) {
        if(idx == 0) {
            return {{}, {nums[0]}};
        }
        else {
            auto res = subsets(nums, idx - 1);
            size_t prevSize = res.size();
            res.reserve(prevSize * 2);
            for (size_t i = 0; i < prevSize; ++i) {
                res.push_back(res[i]);
                res.back().push_back(nums[idx]);
            }
            return res;
        }
    }
};
