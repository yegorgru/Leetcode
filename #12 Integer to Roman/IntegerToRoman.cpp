#include <algorithm>
#include <vector>

#include "Header.h"

//"Integer to Roman"

//https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        return RomanOverThousand(num / 1000) + RomanThousand((num % 1000) / 100) +
            RomanHundred((num % 100) / 10) + RomanTen(num % 10);
    }

private:
    string RomanTen(const int a) {
        string answer;
        if (a == 9) {
            return "IX";
        }
        else if (a == 4) {
            return "IV";
        }
        else if (a > 4) {
            answer = "V";
        }
        for (int i = 0; i < a % 5;i++) {
            answer.push_back('I');
        }
        return answer;
    }

    string RomanHundred(const int a) {
        string answer;
        if (a == 9) {
            return "XC";
        }
        else if (a == 4) {
            return "XL";
        }
        else if (a > 4) {
            answer = "L";
        }
        for (int i = 0; i < a % 5; i++) {
            answer.push_back('X');
        }
        return answer;
    }

    string RomanThousand(const int a) {
        string answer;
        if (a == 9) {
            return "CM";
        }
        else if (a == 4) {
            return "CD";
        }
        else if (a > 4) {
            answer = "D";
        }
        for (int i = 0; i < a % 5; i++) {
            answer.push_back('C');
        }
        return answer;
    }

    string RomanOverThousand(const int a) {
        string answer;
        for (int i = 0; i < a; i++) {
            answer.push_back('M');
        }
        return answer;
    }
};



void Test() {
    Solution s;
    AssertEqual(s.intToRoman(3), "III");
    AssertEqual(s.intToRoman(4), "IV");
    AssertEqual(s.intToRoman(9), "IX");
    AssertEqual(s.intToRoman(58), "LVIII");
    AssertEqual(s.intToRoman(1994), "MCMXCIV");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}