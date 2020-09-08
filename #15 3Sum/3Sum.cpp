#include <set>
#include <map>
#include <utility>
#include <algorithm>

#include "Header.h"

//"3Sum"

//https://leetcode.com/problems/3sum

/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>answer;
        vector<int> tmp;
        tmp.reserve(3);
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i+1; j < nums.size(); j++) {
                for (size_t k = j+1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        tmp = { nums[i],nums[j],nums[k] };
                        sort(tmp.begin(), tmp.end());
                        answer.insert(move(tmp));
                    }
                }
            }
        }
        return vector<vector<int>>(make_move_iterator(answer.begin()),
            make_move_iterator(answer.end()));
    }
};*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        if (*nums.begin() == 0 && *nums.rbegin() == 0) {
            return { {0,0,0} };
        }
        set<vector<int>>DATA;
        int sum = 0;
        for (size_t i = 0; i < nums.size()-2; i++) {
            size_t left_border = i + 1;
            size_t right_border = nums.size() - 1;
            while (left_border < right_border) {
                sum = nums[i] + nums[left_border] + nums[right_border];
                if (sum == 0) {
                    DATA.insert({ nums[i],nums[left_border],nums[right_border] });
                    left_border++;
                    right_border--;
                }
                else if (sum < 0) {
                    left_border++;
                }
                else {
                    right_border--;
                }
            }
        }
        return vector<vector<int>>(make_move_iterator(DATA.begin()), make_move_iterator(DATA.end()));
    }
};

void Test() {
    Solution s;
    {
        vector<int>a = { -1,0,1,2,-1,-4 };
        vector<vector<int>> b = {
            {-1,-1,2},
            {-1,0,1}
        };
        AssertEqual(s.threeSum(a), b);
    }
    {
        vector<int>a = { };
        vector<vector<int>> b = {};
        AssertEqual(s.threeSum(a), b);
    }
    {
        vector<int>a = { 0 };
        vector<vector<int>> b = {};
        AssertEqual(s.threeSum(a), b);
    }
    {
        vector<int>a = { 0,0,0 };
        vector<vector<int>> b = { {0,0,0} };
        AssertEqual(s.threeSum(a), b);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}