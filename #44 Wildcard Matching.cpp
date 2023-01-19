class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> buff(p.size() + 1, vector<bool>(s.size() + 1, false));
        buff[0][0] = true;
        for (size_t i = 1; i <= p.size(); ++i) {
            if (p[i - 1] == '*') {
                auto found = find(buff[i-1].begin(), buff[i-1].end(), true);
                if (found != buff[i-1].end()) {
                    fill(buff[i].begin() + (found - buff[i-1].begin()), buff[i].end(), true);
                }
            }
            else {
                for (size_t j = 1; j <= s.size(); ++j) {
                    if (buff[i - 1][j - 1] && (p[i - 1] == '?' || p[i-1] == s[j-1])) {
                        buff[i][j] = true;
                    }
                }
            }
        }
        return buff[p.size()][s.size()];
    }
};
