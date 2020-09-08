#include <cmath>
#include <string>
#include <string_view>
#include <vector>

#include "Header.h"

//"String to Integer (atoi)"

//https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string str) {
        long long answer = 0;
        size_t pos = 0;
        while (str[pos] == ' ' && pos <str.size()) {
            pos++;
        }
        vector<int>digits;
        bool minus = str[pos] == '-';
        if (minus || !minus && str[pos]=='+') {
            pos++;
        }
        while (str[pos] == '0' && pos < str.size()) {
            pos++;
        }
        while (pos < str.size() && str[pos] > 47 && str[pos] < 58 ) {
            digits.push_back(str[pos] - '0');
            pos++;
        }
        if (digits.size() == 0) {
            return 0;
        }
        else if (digits.size() > 10) {
            if (minus) {
                return INT_MIN;
            }
            else {
                return INT_MAX;
            }
        }
        else {
            for (size_t i = 0; i < digits.size(); i++) {
                answer += digits[i] * pow(10, digits.size() - 1-i);
            }
        }
        if (minus) {
            answer = -answer;
        }
        if (abs(answer) <= abs(INT_MAX)) {
            return (int)answer;
        }
        else if (answer < 0) {
            return INT_MIN;
        }
        else {
            return INT_MAX;
        }
    }
};

void Test() {
    Solution s;
    AssertEqual(s.myAtoi("+1"), 1);
    AssertEqual(s.myAtoi("342"), 342);
    AssertEqual(s.myAtoi("   -42"), -42);
    AssertEqual(s.myAtoi("4193 with words"), 4193);
    AssertEqual(s.myAtoi("words and 987"), 0);
    AssertEqual(s.myAtoi("-91283472332"), -2147483648);
    AssertEqual(s.myAtoi("-2147483647"), -2147483647);
    AssertEqual(s.myAtoi("  0000000000012345678"), 12345678);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}