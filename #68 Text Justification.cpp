class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto start = words.begin();
        size_t currLength = 0;
        vector<string> res;
        auto finish = start;
        for (; finish < words.end(); ++finish) {
            if (currLength + finish->length() + (finish - start) <= maxWidth) {
                currLength += finish->length();
            }
            else {
                string s = *start;
                for (auto it = next(start); it != finish; ++it) {
                    s += string((maxWidth - currLength) / (finish - start - 1) +
                        ((maxWidth - currLength) % (finish - start - 1) >= (it - start)), ' ')
                        + *it;
                }
                s.resize(maxWidth, ' ');
                res.emplace_back(move(s));
                start = finish;
                finish = prev(finish);
                currLength = 0;
            }
        }
        if(start != words.end()) {
            string s = *start;
            for (auto it = next(start); it != words.end(); ++it) {
                s += ' ' + *it;
            }
            s.resize(maxWidth, ' ');
            res.emplace_back(move(s));
        }
        return res;
    }
};
