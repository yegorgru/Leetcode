#include <vector>
#include <algorithm>

//Remove Element

//https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        auto it = std::remove(nums.begin(), nums.end(), val);
        nums.erase(it, nums.end());
        return nums.size();
    }
};