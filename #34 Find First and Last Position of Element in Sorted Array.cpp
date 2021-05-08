class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = std::equal_range(nums.begin(), nums.end(), target);
        std::vector<int> answer;
        if(nums.size() == 0 || range.first != nums.end() && *range.first != target){
            return std::vector<int>{-1,-1};
        }
        if(range.first == nums.end()){
            answer.push_back(-1);
        } 
        else{
            answer.push_back(range.first - nums.begin());
        }
        if(range.second == nums.end()){
            if(nums.back() != target){
                answer.push_back(-1);
            }
            else{
                answer.push_back(nums.size()-1);
            }
        } 
        else{
            answer.push_back(range.second - nums.begin() - 1);
        }
        return answer;
    }
};