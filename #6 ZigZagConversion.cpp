#include <string>
#include <string_view>
#include "Header.h"

using namespace std;

//"ZigZag Conversion"

//https://leetcode.com/problems/zigzag-conversion


//string_view variant
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string_view str = s;
        string answer;
        size_t pos = 0;
        int bottom_field = 0;
        int top_field;
        bool bot;
        answer.reserve(str.size());
        bottom_field = (numRows - 1) * 2;
        while (pos < str.size()) {
            answer.push_back(str[pos]);
            pos += bottom_field;
        }
        for (int i = 2; i < numRows; i++) {
            pos = i-1;
            bottom_field = (numRows - i)*2;
            top_field = (i - 1) * 2;
            bot = true;
            while (pos < str.size()) {
                if (bot) {
                    answer.push_back(str[pos]);
                    pos += bottom_field;
                    bot = false;
                }
                else {
                    answer.push_back(str[pos]);
                    pos += top_field;
                    bot = true;
                }
            }
        }
        pos = numRows - 1;
        top_field = (numRows - 1) * 2;
        while (pos < str.size()) {
            answer.push_back(str[pos]);
            pos += top_field;
        }
        return answer;
    }
};

// string variant
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string answer;
        size_t pos = 0;
        int bottom_field = 0;
        int top_field;
        bool bot;
        answer.reserve(s.size());
        bottom_field = (numRows - 1) * 2;
        while (pos < s.size()) {
            answer.push_back(s[pos]);
            pos += bottom_field;
        }
        for (int i = 2; i < numRows; i++) {
            pos = i - 1;
            bottom_field = (numRows - i) * 2;
            top_field = (i - 1) * 2;
            bot = true;
            while (pos < s.size()) {
                if (bot) {
                    answer.push_back(s[pos]);
                    pos += bottom_field;
                    bot = false;
                }
                else {
                    answer.push_back(s[pos]);
                    pos += top_field;
                    bot = true;
                }
            }
        }
        pos = numRows - 1;
        top_field = (numRows - 1) * 2;
        while (pos < s.size()) {
            answer.push_back(s[pos]);
            pos += top_field;
        }
        return answer;
    }
};