class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char ch){
            return !isalpha(ch) && !isdigit(ch);
        }), s.end());
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char ch){ return tolower(ch); });
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};
