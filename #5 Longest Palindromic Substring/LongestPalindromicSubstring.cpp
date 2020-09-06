#include <string>
#include <string_view>
#include "Header.h"

using namespace std;

//"Longest Palindromic Substring"

//https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        string_view str = s;
        for (auto it = begin(str); it != end(str); it++) {
            for (auto back_it = end(str) - 1; back_it != it; back_it--) {
                if (*back_it == *it) {
                    string_view check(str.substr(it - begin(str), back_it - it + 1));
                    if (isPalindrom(check)) {
                        if (longest.size() < check.size()) {
                            longest = check;
                        }
                        break;
                    }
                }
            }
            if (longest.size() > end(str) - it) {
                break;
            }
        }
        if (longest == "" && s.size() > 0) {
            longest += s[0];
        }
        return longest;
    }
private:
    bool isPalindrom(string_view str) {
        for (size_t i = 0; i < str.size()/2; i++) {
            if (str[i] != str[str.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

void Test() {
    Solution s;
    {
        AssertEqual(s.longestPalindrome("babad"), "bab");
    }
    {
        AssertEqual(s.longestPalindrome("cbbd"), "bb");
    }
    {
        AssertEqual(s.longestPalindrome("AToyotaSatoyoTA"), "AToyotaSatoyoTA");
    }
    {
        AssertEqual(s.longestPalindrome("a"), "a");
    }
    {
        AssertEqual(s.longestPalindrome("sdsaASaNta atNaSAsfg"), "ASaNta atNaSA");
    }
    {
        AssertEqual(s.longestPalindrome("saManaPlanaCanalPanaMaasdadrgdg"),
            "aManaPlanaCanalPanaMa");
    }
    {
        AssertEqual(s.longestPalindrome("Ah sataN sees Natas hAsfsdgergvgy"), "Ah sataN sees Natas hA");
    }
    {
        AssertEqual(s.longestPalindrome("SCDFCDsdvanimallootsfoliateddetailofstoollamina"),
            "animallootsfoliateddetailofstoollamina");
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}