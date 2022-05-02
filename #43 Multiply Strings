class Solution {
public:
    string multiply(string num1, string num2) {
        size_t position = 0;
        std::vector<int>digits(std::max(num1.size(), num2.size()) * 2, 0);
        for(auto first = num1.rbegin(); first != num1.rend(); ++first) {
            position = first - num1.rbegin();
            for(auto second = num2.rbegin(); second != num2.rend(); ++second) {
                int result = (*first - '0') * (*second - '0');
                digits[position] += result % 10;
                digits[position + 1] += result / 10;
                position++;
            }
        }
        for(position = 0; position < digits.size() - 1; position++) {
            int buff = digits[position];
            digits[position] = buff%10;
            digits[position + 1] += buff/10;
        }
        size_t bound = digits.size() - 1;
        while(digits[bound] == 0 && bound != 0) {
            --bound;
        }
        digits.resize(bound + 1);
        std::string answer;
        answer.reserve(digits.size());
        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            answer.push_back('0' + *it);
        }
        return answer;
    }
};
