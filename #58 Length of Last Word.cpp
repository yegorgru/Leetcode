class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.begin() + s.find_last_not_of(" ") + 1, s.end());
        auto found = find(s.rbegin(), s.rend(), ' ');
        return found - s.rbegin();
    }
};
