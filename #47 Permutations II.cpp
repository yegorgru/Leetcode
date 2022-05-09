class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        do {
            answer.insert(nums);
        } while(std::next_permutation(nums.begin(), nums.end()));
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};
