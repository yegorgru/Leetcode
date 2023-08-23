class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() == 1) {
            return count(s.begin(), s.end(), t[0]);
        }
        map<size_t, long long> occurences;
        int counter = 0;
        for(auto ch : s) {
            map<size_t, int> newOccurences;
            for(auto occ : occurences) {
                if(t.size() == occ.first + 2 && t[occ.first+1] == ch) {
                    counter+=occ.second;
                }
                else if(t[occ.first+1] == ch) {
                    newOccurences[occ.first+1] += occ.second;
                }
            }
            for(auto occ : newOccurences) {
                occurences[occ.first] += occ.second;
            }
            if(ch == t[0]) {
                ++occurences[0];
            }
        }
        return counter;
    }
};
