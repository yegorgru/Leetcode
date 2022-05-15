class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(10, 1);
        for(int i = 1; i <= n; ++i) {
            factorials[i] = factorial(i);
        }
        string digits = "123456789";
        digits.resize(n);
        string s;
        --k;
        for(int i = 0; i < n; ++i) {
            size_t pos = k / factorials[n - 1 - i];
            s.push_back(digits[pos]);
            digits.erase(digits.begin() + pos);      
            k %= factorials[n - 1 - i];
        }
        return s;
    }
    
private:
    int factorial(int value) {
        int answer = 1;
        for(int i = 2; i <= value; ++i) {
            answer *= i;
        }
        return answer;
    }
};
