class Solution {
public:
    int minCut(string s) {
        mPalindromes.resize(s.length(), vector<int>(s.length(), 2));
        dp.resize(s.size(),-1);
        return minCut(s,0);
    }

private:
    int minCut(const string &s, int idx){
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int minCuts = INT_MAX;
        for(int i = idx; i < s.size(); i++) {
            if(checkPalindrome(s, idx, i)){
                int cuts = i == s.size() - 1 ? 0 : 1 + minCut(s, i+1);
                minCuts = min(minCuts, cuts);
            }
        }
        dp[idx] = minCuts;
        return dp[idx];
    }

    bool checkPalindrome(const string & s, int firstIdx, int lastIdx) {
        auto& stored = mPalindromes[firstIdx][lastIdx];
        if (stored != 2) {
            return stored;
        }
        for (int i = 0; i < (lastIdx - firstIdx + 1) / 2; ++i) {
            if (s[firstIdx + i] != s[lastIdx - i]) {
                stored = 0;
                return false;
            }
        }
        stored = 1;
        return true;
    }

private:
    vector<vector<int>> mPalindromes;
    vector<int> dp;
};
