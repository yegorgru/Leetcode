class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        calculated.resize(s1.size() + 1, vector<STATUS>(s2.size() + 1, STATUS::UNKNOWN));
        return isInterleave(s1, 0, s2, 0, s3);
    }

private:
    bool isInterleave(const string& s1, size_t idx1, const string& s2, size_t idx2, const string& s3) {
        if (calculated[idx1][idx2] != STATUS::UNKNOWN) {
            return calculated[idx1][idx2] == STATUS::YES;
        }
        if (idx1 + idx2 == s3.size()) {
            return true;
        }
        if (idx1 < s1.size() && s1[idx1] == s3[idx1 + idx2]) {
            if (isInterleave(s1, idx1 + 1, s2, idx2, s3)) {
                calculated[idx1][idx2] = STATUS::YES;
                return true;
            }
        }
        if (idx2 < s2.size() && s2[idx2] == s3[idx1 + idx2]) {
            if (isInterleave(s1, idx1, s2, idx2 + 1, s3)) {
                calculated[idx1][idx2] = STATUS::YES;
                return true;
            }
        }
        calculated[idx1][idx2] = STATUS::NO;
        return false;
    }

private:
    enum class STATUS {
        UNKNOWN,
        YES,
        NO
    };
    vector<vector<STATUS>> calculated;
};
