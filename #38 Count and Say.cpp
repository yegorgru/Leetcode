
// Count and Say

// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {;
        string result = "1";
        for(int i = 1; i < n; i++) {
            result = countAndSay(result);
        }
        return result;
    }
    
private:
    string countAndSay(const string& str) {
        string result;
        int counter = 1;
        char curDigit = str[0];
        for(size_t i = 1; i < str.size(); i++) {
            if(str[i] != curDigit) {
                result += std::to_string(counter);
                result.push_back(curDigit);
                curDigit = str[i];
                counter = 1;
            }
            else {
                counter++;
            }
        }
        result += std::to_string(counter);
        result.push_back(curDigit);
        return result;
    }
};
