class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        res.insert(vector<int>{});
        for (size_t i = 0; i < nums.size(); ++i) {
            vector<vector<int>> curr(res.begin(), res.end());
            for (size_t j = 0; j < curr.size(); ++j) {
                vector<int> n = std::move(curr[j]);
                n.push_back(nums[i]);
                res.insert(move(n));
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};  
