class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        size_t idx = 0;
        for(auto ch : str1) {
            if(ch == str2[idx] || ch == 'z' && str2[idx] == 'a' || ch + 1 == str2[idx]) {
                ++idx;
                if(idx == str2.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
