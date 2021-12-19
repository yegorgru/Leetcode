#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>

//"Combination Sum II"

//https://leetcode.com/problems/combination-sum-ii

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        mTarget = target;
        for(size_t i = 0; i < candidates.size(); i++) {
            if(candidates[i] == mTarget) {
                mCombinations.insert({candidates[i]});
            }
            else if(candidates[i] < mTarget) {
                vector<int> combination{candidates[i]};
                tryFindCombination(candidates, i, combination, candidates[i]);
            }
        }
        return vector<vector<int>>(make_move_iterator(mCombinations.begin()),
                                   make_move_iterator(mCombinations.end()));
    }
    
private:
    void tryFindCombination (vector<int>& candidates, size_t position, 
                   vector<int>& combination, int currentSum) 
    {
        set<int> tried;
        for(size_t i = position + 1; i < candidates.size(); i++) {
            if(tried.find(candidates[i]) != tried.end()) {
                continue;
            }
            tried.insert(candidates[i]);
            if(currentSum + candidates[i] == mTarget) {
                vector<int> newCombination = combination;
                newCombination.push_back(candidates[i]);
                sort(newCombination.begin(), newCombination.end());
                mCombinations.insert(std::move(newCombination));
            }
            else if(currentSum + candidates[i] < mTarget) {
                combination.push_back(candidates[i]);
                tryFindCombination(candidates, i, combination, currentSum + candidates[i]);
                combination.pop_back();
            }
        }
    }
    
    int mTarget;
    set<vector<int>> mCombinations;
};
