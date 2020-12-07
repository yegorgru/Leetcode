#include <vector>
#include <string>
#include <set>
#include <iostream>

//Generate Parentheses

//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res = { "()" };
        generateParenthesis(res, n - 1);
        std::set<std::string> s_res(res.begin(), res.end());
        return std::vector<std::string>(s_res.begin(), s_res.end());
    }
private:
    void generateParenthesis(std::vector<std::string>& res, int n) {
        if (n > 0) {
            size_t size = res.size();
            std::set<std::string>s_res;
            for (size_t i = 0; i < size; i++) {
                int start = 0;
                int finish = 0;
                for (size_t j = 0; j != res[i].size(); j++) {
                    if (res[i][j] == '(') {
                        start = 1;
                        finish = 0;
                        auto cur_j = j+1;
                        while (start >= finish && cur_j < res[i].size()) {
                            if (res[i][cur_j] == '(') {
                                start++;
                            }
                            else if (res[i][cur_j] == ')' && cur_j - j > 1) {
                                finish++;
                                std::string new_str = res[i];
                                new_str.insert(new_str.begin() + j, '(');
                                new_str.insert(new_str.begin() + cur_j+1, ')');
                                s_res.insert(new_str);
                            }
                            cur_j++;
                        }
                    }
                }
                for (size_t j = 0; j != res[i].size(); j++) {
                    std::string new_str = res[i];
                    new_str.insert(new_str.begin() + j, '(');
                    new_str.insert(new_str.begin() + j + 1, ')');
                    s_res.insert(new_str);
                }
                std::string new_str = res[i];
                new_str.push_back('(');
                new_str.push_back(')');
                s_res.insert(new_str);
            }
            res = std::vector<std::string>(s_res.begin(),s_res.end());
            generateParenthesis(res, n - 1);
        }
    }
};

int main() {
    Solution sol;
    for (auto& i : sol.generateParenthesis(7)) {
        std::cout << i << std::endl;
    }
}