#include <set>
#include <utility>
#include <algorithm>

#include "Header.h"

//"4Sum"

//https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        set<vector<int>>answer;
        sort(nums.begin(), nums.end());
        int sum = 0;
        int part_sum = 0;
        vector<int>tmp;
        tmp.reserve(4);
        for (size_t i = 0; i < nums.size() - 3; i++) {
            for (size_t j = i+1; j < nums.size() - 2; j++) {
                part_sum = nums[i] + nums[j];
                size_t left_border = j + 1;
                size_t right_border = nums.size() - 1;
                while (left_border < right_border) {
                    sum = part_sum + nums[left_border] + nums[right_border];
                    if (sum == target) {
                        tmp = { nums[i],nums[j],nums[left_border],nums[right_border] };
                        answer.insert(move(tmp));
                        left_border++;
                        right_border--;
                    }
                    else if (sum < target) {
                        left_border++;
                    }
                    else {
                        right_border--;
                    }
                }
            }
        }
        return vector<vector<int>>(make_move_iterator(answer.begin()), make_move_iterator(answer.end()));
    }
};