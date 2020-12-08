#include <string>
#include <vector>
#include <map>

//Substring with Concatenation of All Words

//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

//Не проходить по часу (через map<size_t, std::string>s_words)
/*class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        if (words.size() == 0) {
            return std::vector<int>();
        }
        std::map<size_t, std::string>s_words;
        std::map<std::string, int>words_number;
        for (auto& str : words) {
            words_number[str]++;
        }
        size_t loop_number = 0;
        for (auto it = words_number.begin(); it != words_number.end(); it++) {
            loop_number += it->second;
        }
        std::vector<int> res;
        for (auto itt = words_number.begin(); itt != words_number.end();itt++) {
            size_t pos = 0;
            while (true) {
                if (pos < s.size()) {
                    size_t new_pos = s.find(itt->first, pos);
                    if (new_pos != s.npos) {
                        s_words[new_pos] = itt->first;
                        pos = new_pos + 1;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        for (auto it = s_words.begin(); it != s_words.end(); it++) {
            std::map<std::string, int>check_map;
            check_map[it->second]++;
            size_t prev = it->first;
            auto loop_it = it;
            loop_it++;
            for (int i = 1; i<loop_number; i++, loop_it++) {
                if (loop_it!= end(s_words) && loop_it->first - prev < words[0].size()) {
                    i--;
                    continue;
                }
                else if (loop_it==end(s_words) ||
                    loop_it->first - prev != words[0].size()) {
                    break;
                }
                else {
                    check_map[loop_it->second]++;
                    prev = loop_it->first;
                }
            }
            if (check_map == words_number) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};*/

//проходить, через std::vector<std::string>s_words(s.size()), не треба кожен раз бінарний пошук. Але додалося декілька перевірок
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        if (words.size() == 0) {
            return std::vector<int>();
        }
        std::map<std::string, int>words_number;
        for (auto& str : words) {
            words_number[str]++;
        }
        std::vector<std::string>s_words(s.size());
        size_t loop_number = 0;
        for (auto it = words_number.begin(); it != words_number.end(); it++) {
            loop_number += it->second;
        }
        std::vector<int> res;
        for (auto itt = words_number.begin(); itt != words_number.end();itt++) {
            size_t pos = 0;
            while (true) {
                if (pos < s.size()) {
                    size_t new_pos = s.find(itt->first, pos);
                    if (new_pos != s.npos) {
                        s_words[new_pos] = itt->first;
                        pos = new_pos + 1;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        for (size_t ii = 0; ii < s_words.size()-words.size()+1; ii++) {
            if (s_words[ii] == "") {
                continue;
            }
            std::map<std::string, int>check_map;
            check_map[s_words[ii]]++;
            size_t prev = ii;
            auto loop_i = ii+1;
            for (int i = 1; i<loop_number; i++, loop_i++) {
                if (loop_i == s_words.size()) {
                    break;
                }
                if (s_words[loop_i]=="" || loop_i < s_words.size() && loop_i - prev < words[0].size()) {
                    i--;
                    continue;
                }
                else if (loop_i - prev != words[0].size()) {
                    break;
                }
                else if(s_words[loop_i] != ""){
                    check_map[s_words[loop_i]]++;
                    prev = loop_i;
                }
            }
            if (check_map == words_number) {
                res.push_back(ii);
            }
        }
        return res;
    }
};