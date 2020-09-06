#include <vector>
#include <map>

using namespace std;

// "Two sum"

//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, size_t>DATA;
        int half_count = -1;
        int half_target = -1;
        bool possible_half = false;
        if (target % 2 == 0) {
            possible_half = true;
            half_target = target / 2;
            half_count = 0;
        }
        for (auto it = begin(nums); it != end(nums); it++) {
            if (possible_half && *it == half_target) {
                if (half_count == 1) {
                    return { int(DATA[half_target]), int(it - begin(nums)) };
                }
                else {
                    half_count = 1;
                    DATA[half_target] = it - begin(nums);
                    continue;
                }
            }
            else {
                DATA[*it] = it - begin(nums);
            }
        }
        for (auto it = begin(DATA); it != end(DATA); it++) {
            auto searched = DATA.find(target - it->first);
            if (searched != end(DATA)) {
                return { int(it->second), int(searched->second) };
            }
        }
        return { -1,-1 };
    }
};