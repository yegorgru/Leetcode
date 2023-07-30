class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        s1Start = s1.begin();
        memorized = vector<vector<vector<int>>>(s2.size(), vector<vector<int>>(s1.size(), vector<int>(s1.size() + 1, 2)));
        return isScramble(s1.begin(), s1.end(), s2, 0);
    }

private:
    bool isScramble(string::const_iterator sb, string::const_iterator se, const string& s2, size_t idx) {
        if(memorized[idx][sb - s1Start][se - sb] != 2) {
            return memorized[idx][sb - s1Start][se - sb];
        }
        if (!is_permutation(sb, se, s2.begin() + idx)) {
            memorized[idx][sb - s1Start][se - sb] = 0;
            return false;
        }
        if (se - sb == 1) {
            memorized[idx][sb - s1Start][se - sb] = *sb == s2[idx];
            return *sb == s2[idx];
        }
        for (size_t i = 1; i < se - sb; ++i) {
            if (isScramble(sb, sb + i, s2, idx) && isScramble(sb + i, se, s2, idx + i)) {
                memorized[idx][sb - s1Start][se - sb] = 1;
                return true;
            }
            if (isScramble(sb + i, se, s2, idx) && isScramble(sb, sb + i, s2, idx + se - sb - i)) {
                memorized[idx][sb - s1Start][se - sb] = 1;
                return true;
            }
        }
        memorized[idx][sb - s1Start][se - sb] = 0;
        return false;
    }

private:
    vector<vector<vector<int>>> memorized;
    string::const_iterator s1Start;
};
