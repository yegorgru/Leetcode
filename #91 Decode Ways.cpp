class Solution {
public:
    int numDecodings(string s) {
        calculated.resize(s.size(), -1);
        int sum = numDecodings(s, 0);
        return sum == -1 ? 0 : sum;
    }

private:
    int numDecodings(const string& s, size_t idx) {
        if (calculated[idx] != -1) {
            return calculated[idx];
        }
        if (idx == s.size() - 1) {
            calculated[idx] = find(v.begin(), v.end(), string(s.begin() + idx, s.end())) != v.end() ? 1 : -1;
        }
        else if (idx == s.size() - 2) {
            int sum = 0;
            if (find(v.begin(), v.end(), string(s.begin() + idx, s.begin() + idx + 1)) != v.end() &&
                find(v.begin(), v.end(), string(s.begin() + idx + 1, s.end())) != v.end()) {
                sum = 1;
            }
            if (find(v.begin(), v.end(), string(s.begin() + idx, s.end())) != v.end()) {
                ++sum;
            }
            calculated[idx] = sum != 0 ? sum : -1;
        }
        else {
            string nextOne = string(s.begin() + idx, s.begin() + idx + 1);
            int sumOne = find(v.begin(), v.end(), nextOne) != v.end() ? numDecodings(s, idx + 1) : -1;
            string nextTwo = string(s.begin() + idx, s.begin() + idx + 2);
            int sumTwo = find(v.begin(), v.end(), nextTwo) != v.end() ? numDecodings(s, idx + 2) : -1;
            if (sumOne == -1 && sumTwo == -1) {
                calculated[idx] = -1;
            }
            else {
                calculated[idx] = (sumOne == -1 ? 0 : sumOne) + (sumTwo == -1 ? 0 : sumTwo);
            }
        }
        return calculated[idx];
    }

private:
    vector<string> v = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26"
    };
    vector<size_t> calculated;
};
