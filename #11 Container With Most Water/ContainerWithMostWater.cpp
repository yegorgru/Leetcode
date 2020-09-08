#include <algorithm>
#include <vector>

#include "Header.h"

//"Container With Most Water"

//https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        return maxArea(height.begin(), height.end() - 1);
    }

    int maxArea(vector<int>::iterator max_left, vector<int>::iterator max_right) {
        auto search_left = max_left;
        auto search_right = max_right;
        int answer = (max_right - max_left) * min(*max_left, *max_right);
        if (max_right - max_left < 2) {
            return answer;
        }
        int buf_intl,buf_intr;
        auto buf_itl = max_left;
        auto buf_itr = max_right;
        while (!(*search_left > * max_left) && search_left < max_right) {
            search_left++;
        }
        if (search_left == max_right) {
            int buf;
            for (auto it = max_left + 1; it != max_right;it++) {
                buf = (it - max_left) * min(*max_left, *it);
                answer = max(answer, buf);
            }
            return answer;
        }
        buf_intl = (max_right - search_left) * min(*max_right, *search_left);
        buf_itl = search_left;
        while (!(*search_right > * max_right) && search_right > max_left) {
            search_right--;
        }
        if (search_right == max_left) {
            int buf;
            for (auto it = max_right - 1; it != max_left; it--) {
                buf = (max_right - it) * min(*max_right, *it);
                answer = max(answer, buf);
            }
            return answer;
        }
        buf_intr = (search_right - max_left) * min(*search_right, *max_left);
        buf_itr = search_right;
        if (buf_intr == buf_intl && buf_intl > answer) {
            return max(maxArea(buf_itl, max_right), maxArea(max_left, buf_itr));
        }
        else if (buf_intr <= answer && buf_intl <= answer) {
            int buf = max(maxArea(buf_itl, max_right), maxArea(max_left, buf_itr));
            return max(buf, answer);
        }
        else if (buf_intr > buf_intl) {
            return maxArea(max_left, buf_itr);
        }
        else if (buf_intl > buf_intr) {
            return maxArea(buf_itl, max_right);
        }
        else {
            return answer;
        }
    }
};



void Test() {
    Solution s;
    {
        vector<int>a{ 1,8,6,2,5,4,8,3,7 };
        vector<int>b{ 5,1,1,1,5 };
        vector<int>c{ 5, 2, 12, 1, 5, 3, 4, 11, 9, 4 };
        AssertEqual(s.maxArea(b), 20);
        AssertEqual(s.maxArea(a), 49);
        AssertEqual(s.maxArea(c), 55);
        vector<int>d(15);
        for (size_t i = 15; i > 0; i--) {
            d[15 - i] = i;
        }
        AssertEqual(s.maxArea(d), 56);
        reverse(d.begin(), d.end());
        AssertEqual(s.maxArea(d), 56);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}