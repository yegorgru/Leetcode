class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        mCalculated.resize(2, vector<CalculatedValue>(s.size(), nullopt));
        return restoreIpAddresses(s, 0, 3);
    }

private:
    vector<string> restoreIpAddresses(const string& s, size_t idx, int numberOfDots) {
        if (numberOfDots != 3 && mCalculated[numberOfDots - 1][idx] != nullopt) {
            return *mCalculated[numberOfDots - 1][idx];
        }
        vector<string> res;
        if (numberOfDots == 1) {
            for (size_t i = idx + 1; i < s.size(); ++i) {
                string left = string(s.begin() + idx, s.begin() + i);
                string right = string(s.begin() + i, s.end());
                if (isValidNumber(left) && isValidNumber(right)) {
                    res.emplace_back(left + "." + right);
                }
            }
            if (res.size() > 0) {
                mCalculated[numberOfDots - 1][idx] = res;
                return res;
            }
        }
        else {
            for (size_t i = 1; i < 4 && idx + i < s.size(); ++i) {
                string next(s.begin() + idx, s.begin() + idx + i);
                if (isValidNumber(next)) {
                    for (const auto& nextS : restoreIpAddresses(s, idx + i, numberOfDots - 1)) {
                        res.emplace_back(next + "." + nextS);
                    }
                }
            }
            if (res.size() > 0) {
                if (numberOfDots != 3) {
                    mCalculated[numberOfDots - 1][idx] = res;
                }
                return res;
            }
        }
        return {};
    }

    bool isValidNumber(const string& s) {
        return s.size() < 4 && (s == "0" || s[0] != '0' && stoi(s) < 256);
    }

private:
    using CalculatedValue = optional<vector<string>>;
    using CalculatedStorage = vector<vector<CalculatedValue>>;
    CalculatedStorage mCalculated;
};
