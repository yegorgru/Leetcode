class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        do {
            answer.push_back(nums);
        } while(std::next_permutation(nums.begin(), nums.end()));
        return answer;
    }
};
