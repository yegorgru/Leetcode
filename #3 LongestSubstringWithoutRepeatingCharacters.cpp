#include <string>
#include <string_view>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string_view str = s;
        size_t maximum = 0;

        bool was_end = false;

        size_t cur_begin=0;

        set<char>NonRepetitive;
        for (auto it = begin(str); it != end(str);it++) {
            if (NonRepetitive.find(*it) == end(NonRepetitive)) {
                was_end = false;
                NonRepetitive.insert(*it);
            }
            else {
                was_end = true;

                maximum = max(maximum, NonRepetitive.size());
                size_t ind = 0;
                for (auto remove_it = begin(str)+cur_begin; *remove_it != *it; remove_it++) {
                    NonRepetitive.erase(*remove_it);
                    cur_begin++;
                }
                cur_begin++;
            }
        }

        if (!was_end) {
            maximum = max(maximum,NonRepetitive.size());
        }

        return int(maximum);
    }
};