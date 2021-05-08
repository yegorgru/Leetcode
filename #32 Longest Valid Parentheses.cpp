class Solution {
public:
    int longestValidParentheses(const string& s) {
        int longest = 0;
        for(size_t i=0;i<s.size();++i){
            if(s[i]==')') continue;
            int cur = longestValidForSomeIndex(s, i);
            if(cur > longest){
                longest = cur;
            }
        }
        return longest;
    }
    
private:
    int longestValidForSomeIndex(const string& s, size_t index) {
        int difference = 0;
        int longest = 0;
        for(size_t i=index;i<s.size();++i){
            if(s[i] == '(') ++difference;
            else --difference;
            if(difference < 0) return longest;
            else if(difference == 0){
                longest = i-index+1;
            }
        }
        return longest;
    }
};