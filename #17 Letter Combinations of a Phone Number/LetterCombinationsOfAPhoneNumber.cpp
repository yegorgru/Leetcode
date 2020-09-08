#include <set>
#include <utility>
#include <algorithm>

#include "Header.h"

//"Letter Combinations of a Phone Number"

//https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        set<string> answer;
        set<string>tmp;
        map<char, vector<char>>DATA;
        DATA['2'] = { 'a','b','c' };
        DATA['3'] = { 'd','e','f' };
        DATA['4'] = { 'g','h','i' };
        DATA['5'] = { 'j','k','l' };
        DATA['6'] = { 'm','n','o' };
        DATA['7'] = { 'p','q','r','s' };
        DATA['8'] = { 't','u','v' };
        DATA['9'] = { 'w','x','y','z' };
        for (size_t k = 0; k < DATA[digits[0]].size();k++) {
            answer.insert(string("") += DATA[digits[0]][k]);
        }
        for (auto i = begin(digits)+1; i != end(digits); i++) {
            tmp = move(answer);
            for (auto j = begin(tmp); j != end(tmp); j++) {
                for (auto k = begin(DATA[*i]); k != end(DATA[*i]); k++) {
                    answer.insert(string(*j) += *k);
                }
            }
        }
        return vector<string>(answer.begin(), answer.end());
    }
};

void Test() {
    Solution s;
    {
        vector<string>a = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
        AssertEqual(s.letterCombinations("23"), a);
    }
    {
        vector<string>a = { };
        AssertEqual(s.letterCombinations(""), a);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}