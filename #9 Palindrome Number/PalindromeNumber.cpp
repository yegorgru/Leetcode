#include <cmath>
#include <vector>

#include "Header.h"

//"Palindrome Number"

//https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        else {
            int digit = 10;
            long long to_check = 0;
            int copy_x = x;
            while (copy_x > 0) {
                to_check = to_check * 10 + copy_x % 10;
                copy_x /= 10;
            }
            return x == to_check;
        }
    }
};

/*class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        else {
            vector<int>digits;
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }
            for (size_t i = 0; i < digits.size() / 2; i++) {
                if (digits[i] != digits[digits.size() - 1 - i]) {
                    return false;
                }
            }
            return true;
        }
    }
};*/

void Test() {
    Solution s;
    ASSERT(s.isPalindrome(121));
    ASSERT(!s.isPalindrome(-121));
    ASSERT(!s.isPalindrome(10));
    ASSERT(s.isPalindrome(1));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}