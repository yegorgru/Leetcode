#include <vector>
#include <algorithm>

//Remove Duplicates from Sorted Array

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return nums.size();
    }
};