#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "doctest.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        b = 0;
        e = 0;
        int min = INCORRECT_MIN;
        int minB = 0;
        int minE = 1'000'000;
        tMap.clear();
        for (auto ch : t) {
            ++tMap[ch];
        }
        tChars = CharUnique(t.begin(), t.end());
        currentChars = tChars;
        windowMap = CharCounts{};
        while (e != s.size()) {
            if (!expandRight(s)) {
                break;
            }
            minimizeLeft(s);
            if (min > e - b) {
                min = e - b;
                minB = b;
                minE = e;
            }
            if (b < s.size()) {
                currentChars.insert(s[b]);
                --windowMap[s[b]];
                ++b;
            }
        }
        if (INCORRECT_MIN != min) {
            return string(s.begin() + minB, s.begin() + minE);
        }
        else {
            return "";
        }
    }

private:
    bool expandRight(const string& s) {
        while (e < s.size()) {
            char ch = s[e];
            auto found = tMap.find(ch);
            if (found != tMap.end()) {
                int currentWindowValue = ++windowMap[s[e]];
                if (currentWindowValue >= found->second) {
                    currentChars.erase(s[e]);
                    if (currentChars.size() == 0) {
                        ++e;
                        return true;
                    }
                }
            }
            ++e;
        }
        return false;
    }

    void minimizeLeft(const string& s) {
        while (b < e) {
            char ch = s[b];
            auto found = tMap.find(ch);
            if (found != tMap.end()) {
                int& currentWindowValue = windowMap[s[b]];
                if (currentWindowValue > found->second) {
                    --currentWindowValue;
                }
                else {
                    return;
                }
            }
            ++b;
        }
    }

private:
    const int INCORRECT_MIN = 1'000'000;
    int b = 0;
    int e = 0;
    using CharCounts = unordered_map<char, int>;
    using CharUnique = unordered_set<char>;
    CharCounts tMap;
    CharCounts windowMap;
    CharUnique tChars;
    CharUnique currentChars;
};

TEST_CASE("testing Solution") {
    Solution s;
    CHECK_EQ(s.minWindow("ADOBECODEBANC", "ABC"), "BANC");
    CHECK_EQ(s.minWindow("a", "a"), "a");
    CHECK_EQ(s.minWindow("a", "aa"), "");
    CHECK_EQ(s.minWindow("ab", "a"), "a");
}
