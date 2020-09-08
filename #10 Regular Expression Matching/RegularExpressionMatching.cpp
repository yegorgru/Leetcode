#include <cmath>
#include <vector>
#include <set>
#include <utility>

#include "Header.h"

//"Regular Expression Matching"

//https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        set<pair<string, string>> global;
        return isMatch(s, p, global);
    }

    bool isMatch(string s, string p,set<pair<string,string>>& global) {
        global.insert({ s,p });
        if (p.size() == 0 && s.size() != 0) {
            return false;
        }
        if (s.size() == 0 && (p.size() == 0 || p.size() == 2 && p[1] == '*')) {
            return true;
        }
        size_t minimum = p.size();
        char ch = 1;
        size_t count = 0;
        size_t posS = 0;
        size_t posP = 0;
        bool was_loop = false;
        set<string>without_star;
        for (auto i = begin(p)+1; i != end(p); i++) {
            if (*i == '*') {
                string tmp = string(begin(p), i - 1) + string(i + 1, end(p));
                if (global.find({ s,tmp }) == end(global)) {
                    global.insert({ s,tmp });
                    without_star.insert(move(tmp));
                }
                minimum -= 2;
            }
        }
        if (minimum > s.size()) {
            return false;
        }
        for (auto i = begin(without_star); i != end(without_star); i++) {
            if (isMatch(s,*i,global)) {
                return true;
            }
        }
        for (; posP < p.size() || posS < s.size(); posP++) {
            if (posP + 1 < p.size() && p[posP+1] == '*') {
                if (p[posP] == '.') {
                    if (posP + 2 == p.size()) {
                        return true;
                    }
                    else {
                        char searched = p[posP + 2];
                        set<string>possible_ends;
                        string p2(p.begin() + posP + 2, end(p));
                        for (auto i = begin(s) + posS; i != end(s); i++) {
                            if (*i == searched || searched == '.') {
                                string tmp(string(i, end(s)));
                                if (global.find({ tmp,p2 }) == end(global)) {
                                    global.insert({ tmp,p2 });
                                    possible_ends.insert(move(tmp));
                                }
                            }
                        }
                        for (auto i = begin(possible_ends); i != end(possible_ends); i++) {
                            if (isMatch(*i, p2,global)) {
                                return true;
                            }
                        }
                    }
                }
                else if (p[posP] != s[posS]) {
                    was_loop = false;
                    posP ++;
                }
                else {
                    count = 0;
                    ch = p[posP];
                    while (s[posS] == p[posP] && posS < s.size()) {
                        posS++;
                        count++;
                    }
                    if (count > 0) {
                        was_loop = true;
                    }
                    posP ++;
                }
            }
            else if (p[posP] == '.') {
                if (was_loop && count > 1) {
                    string p3 = string(begin(p),begin(p)+posP)+string(begin(p) + posP+1,end(p));
                    if (global.find({ s,p3 }) == end(global)) {
                        if (isMatch(s, p3, global)) {
                            return true;
                        }
                        else {
                            posP--;
                        }
                    }
                    else {
                        posS++;
                        was_loop = false;
                    }
                }
                else {
                    posS++;
                    was_loop = false;
                }
            }
            else if (p[posP] == ch && was_loop) {
                size_t over = 0;
                while (p[posP] == ch && posP<p.size()) {
                    over++;
                    posP++;
                }
                posP--;
                if (over > count) {
                    return false;
                }
                was_loop = false;
            }
            else if(p[posP]==s[posS]){
                posS++;
                was_loop = false;
            }
            else {
                return false;
            }
        }
        if (posP != p.size() || posS != s.size()) {
            return false;
        }
        else {
            return true;
        }
    }
};



void Test() {
    Solution s;
    ASSERT(!s.isMatch("aa","a"));
    ASSERT(s.isMatch("aa", "a*c*a"));
    ASSERT(s.isMatch("aa", "a*"));
    ASSERT(s.isMatch("ab", ".*"));
    ASSERT(s.isMatch("aab", "c*a*b"));
    ASSERT(!s.isMatch("mississippi", "mis*is*p*."));
    ASSERT(s.isMatch("mississippi", "mis*is*ip*."));
    ASSERT(s.isMatch("miippi", "mis*is*p*i"));
    ASSERT(s.isMatch("miippikkkkk", "mis*is*p*i.*"));
    ASSERT(s.isMatch("miippik", "mis*is*p*i.*"));
    ASSERT(s.isMatch("aaa", "a*a"));
    ASSERT(s.isMatch("aaa", "a*aa"));
    ASSERT(s.isMatch("aaaaaaaaaaaaaa", "a*aa"));
    ASSERT(!s.isMatch("aaa", "a*aaaa"));
    ASSERT(s.isMatch("aaab", "a*aab"));
    ASSERT(s.isMatch("aaa.", "a*aa."));
    ASSERT(s.isMatch("aaa.", "a*aa.*"));
    ASSERT(s.isMatch("aaa.k", "a*aa.*k"));
    ASSERT(!s.isMatch("abcd", "abc"));
    ASSERT(!s.isMatch("abc", "abcd"));
    ASSERT(s.isMatch("aaa", "ab*a*c*a"));
    ASSERT(s.isMatch("", ".*"));
    ASSERT(s.isMatch("", ""));
    ASSERT(s.isMatch("abcdede","ab.*de"));
    ASSERT(s.isMatch("", "c*c*"));
    ASSERT(!s.isMatch("", "..*"));
    ASSERT(!s.isMatch("aaaccbccbcbaabcaa","c*a*.*a*.*c*.c*.a*c"));
    ASSERT(s.isMatch("bbbacbaacacaaaba", "b*c*b*.a.*a*.*.*b*"));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}