class Solution {
public:
    bool isNumber(string s) {
        auto e = s.find_first_of("eE");
        if(e != string::npos) {
            string ss(s.begin(), s.begin() + e);
            string_view sv(ss);
            if(isInt(sv) || isDecimal(sv)) {
                return isInt(string(s.begin() + e + 1, s.end()));
            }
            return false;
        }
        else {
            return isInt(s) || isDecimal(s);   
        }
    }
    
private:
    bool isDecimal(string_view s) {
        if(s.length() == 0) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s.remove_prefix(1);
        }
        if(s[0] == '.') {
            s.remove_prefix(1);
            return s.length() > 0 && isDigits(s) == s.length();
        }
        auto pos = isDigits(s);
        if(pos == s.length()) {
            return false;
        }
        else if(s[pos] == '.') {
            s.remove_prefix(pos + 1);
            return s.length() == 0 || isDigits(s) == s.length();
        }
        return false;
    }
    
    bool isInt(string_view s) {
        if(s.length() == 0) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s.remove_prefix(1);
        }
        return s.length() > 0 && isDigits(s) == s.length();
    }
    
    size_t isDigits(string_view s) {
        if(s.length() == 0) {
            return 0;
        }
        for(size_t i = 0; i < s.length(); ++i) {
            if(s[i] < '0' || s[i] > '9') {
                return i;
            }
        }
        return s.length();
    }
};
