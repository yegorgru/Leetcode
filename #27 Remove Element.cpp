#include <vector>
#include <algorithm>

//Remove Duplicates from Sorted Array

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        auto it = std::remove(nums.begin(), nums.end(), val);
        nums.erase(it, nums.end());
        return nums.size();
    }
};