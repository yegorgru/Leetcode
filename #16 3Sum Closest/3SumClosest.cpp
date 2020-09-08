#include <set>
#include <map>
#include <utility>
#include <algorithm>

#include "Header.h"

//"3Sum Closest"

//https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums,int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        unsigned int difference = UINT_MAX;
        int min_dif_sum = INT_MAX;
        int check = 0;
        for (size_t i = 0; i < nums.size()-2; i++) {
            size_t left_border = i + 1;
            size_t right_border = nums.size() - 1;
            while (left_border < right_border) {
                sum = nums[i] + nums[left_border] + nums[right_border];
                check = sum - target;
                if (check == 0) {
                    return target;
                }
                else if (check < 0) {
                    left_border++;
                }
                else {
                    right_border--;
                }
                if (difference > abs(check)) {
                    difference = abs(check);
                    min_dif_sum = sum;
                }
            }
        }
        return min_dif_sum;
    }
};

void Test() {
    Solution s;
    {
        vector<int>a = { -1,2,1,-4 };
        AssertEqual(s.threeSumClosest(a,1), 2);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}