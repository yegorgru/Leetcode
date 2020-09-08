#include <map>

#include "Header.h"

//"Valid Parentheses"

//https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) {
            return false;
        }
        else {
            map<char, char>DATA;
            DATA['('] = ')';
            DATA['{'] = '}';
            DATA['['] = ']';
            map<char, bool>BACK_OR_NO;
            BACK_OR_NO['('] = 1;
            BACK_OR_NO['{'] = 1;
            BACK_OR_NO['['] = 1;
            BACK_OR_NO['}'] = 0;
            BACK_OR_NO[')'] = 0;
            BACK_OR_NO[']'] = 0;
            vector<char>to_close;
            for (auto it = begin(s); it != end(s); it++) {
                if (BACK_OR_NO[*it] == 0 &&
                    (to_close.size() == 0 || DATA[to_close.back()] != *it)) {
                    return false;
                }
                else if (BACK_OR_NO[*it]==1) {
                    to_close.push_back(*it);
                }
                else {
                    to_close.pop_back();
                }
            }
            return to_close.empty();
        }
    }
};