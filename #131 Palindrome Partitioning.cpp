class Solution {
public:
    vector<vector<string>> partition(string s) {
        partition(s, 0, {});  
        return mResult;     
    }

private:
    void partition(const string& s, size_t b, vector<string> currPartition) {
        if(b == s.length()) {
            mResult.push_back(currPartition);
            return;
        }
        else if(b == s.length() - 1) {
            currPartition.push_back(string(s.begin() + b, s.end()));
            mResult.push_back(currPartition);
            return;
        }
        for(size_t i = b; i < s.length(); ++i) {
            if(checkPalindrome(s, b, i)) {
                auto nextPartition = currPartition;
                nextPartition.push_back(string(s.begin() + b, s.begin() + i + 1));
                partition(s, i + 1, nextPartition);
            }
        }
    }

    bool checkPalindrome(const string& s, size_t firstIdx, size_t lastIdx) {
        for(int i = 0; i < (lastIdx - firstIdx + 1) / 2; ++i) {
            if(s[firstIdx + i] != s[lastIdx - i]) {
                return false;
            }
        }
        return true;
    } 

private:
    vector<vector<string>> mResult;
};
