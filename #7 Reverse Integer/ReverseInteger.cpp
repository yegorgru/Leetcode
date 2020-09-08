#include <cmath>

#include "Header.h"

//"Reverse Integer"

//https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {

        long long answer = 0;

        while (x) {
            answer = answer * 10 + x % 10;
            x /= 10;
        }

        if (answer > INT_MAX || answer < INT_MIN) {
            return 0;
        }

        return (int)answer;
    }
};



void Test() {
    Solution s;
    AssertEqual(s.reverse(123), 321);
    AssertEqual(s.reverse(-123), -321);
    AssertEqual(s.reverse(120), 21);
    AssertEqual(s.reverse(5), 5);
    AssertEqual(s.reverse(0), 0);
    AssertEqual(s.reverse(12345), 54321);
    AssertEqual(s.reverse(-12345), -54321);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}