#include <string>
#include <map>

#include "Header.h"

//"Roman to Integer"

//https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        map<char, int>DATA;
        DATA['M'] = 1000;
        DATA['D'] = 500;
        DATA['C'] = 100;
        DATA['L'] = 50;
        DATA['X'] = 10;
        DATA['V'] = 5;
        DATA['I'] = 1;

        auto it = begin(s);
        for (; it != end(s) - 1; it++) {
            if (DATA[*(it + 1)] > DATA[*it]) {
                answer -= DATA[*it];
            }
            else {
                answer += DATA[*it];
            }
        }
        answer += DATA[*it];
        return answer;
    }
};

void Test() {
    Solution s;
    AssertEqual(s.romanToInt("III"), 3);
    AssertEqual(s.romanToInt("IV"), 4);
    AssertEqual(s.romanToInt("IX"), 9);
    AssertEqual(s.romanToInt("LVIII"), 58);
    AssertEqual(s.romanToInt("MCMXCIV"), 1994);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}