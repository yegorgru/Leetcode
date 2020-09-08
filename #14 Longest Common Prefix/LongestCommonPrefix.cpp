#include <string>
#include <map>

#include "Header.h"

//"Longest Common Prefix"

//https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string answer;
        size_t pos = 0;
        bool end = false;
        while (pos < strs[0].size()) {
            char ch = strs[0][pos];
            for (const string& str : strs) {
                try
                {
                    if (str[pos] != ch) {
                        end = true;
                        break;
                    }
                }
                catch (const std::exception&)
                {
                    end = true;
                    break;
                }
            }
            if (end) {
                break;
            }
            else {
                answer += ch;
                pos++;
            }
        }
        return answer;
    }
};

void Test() {
    Solution s;
    {
        vector<string>a = { "flower","flow","flight" };
        AssertEqual(s.longestCommonPrefix(a), "fl");
    }
    {
        vector<string>a = { "dog","racecar","car" };
        AssertEqual(s.longestCommonPrefix(a), "");
    }
    {
        vector<string>a = { "flower","flowerrr","flowerrrght" };
        AssertEqual(s.longestCommonPrefix(a), "flower");
    }
    {
        vector<string>a = { "flower","flow","flowerrrght" };
        AssertEqual(s.longestCommonPrefix(a), "flow");
    }
    {
        vector<string>a = { "","flow","flowerrrght" };
        AssertEqual(s.longestCommonPrefix(a), "");
    }
    {
        vector<string>a = { "","","" };
        AssertEqual(s.longestCommonPrefix(a), "");
    }
    {
        vector<string>a = { "dog","dog","dog" };
        AssertEqual(s.longestCommonPrefix(a), "dog");
    }
    {
        vector<string>a = { };
        AssertEqual(s.longestCommonPrefix(a), "");
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
}