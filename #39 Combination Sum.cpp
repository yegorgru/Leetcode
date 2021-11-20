#include <vector>

//https://leetcode.com/problems/combination-sum/

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        mTarget = target;
        mCombinations.reserve(150);
        for(size_t i = 0; i < candidates.size(); i++) {
            if(candidates[i] == mTarget) {
                mCombinations.push_back({candidates[i]});
            }
            else if(candidates[i] < mTarget) {
                vector<int> combination{candidates[i]};
                tryFindCombination(candidates, i, combination, candidates[i]);
            }
        }
        return mCombinations;
    }
    
private:
    void tryFindCombination (vector<int>& candidates, size_t position, 
                   vector<int>& combination, int currentSum) 
    {
        for(size_t i = position; i < candidates.size(); i++) {
            if(currentSum + candidates[i] == mTarget) {
                mCombinations.push_back(combination);
                mCombinations.back().push_back(candidates[i]);
            }
            else if(currentSum + candidates[i] < mTarget) {
                combination.push_back(candidates[i]);
                tryFindCombination(candidates, i, combination, currentSum + candidates[i]);
                combination.pop_back();
            }
        }
    }
        
    int mTarget;
    vector<vector<int>> mCombinations;
};
