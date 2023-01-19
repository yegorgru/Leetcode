struct Comparator {
    bool operator()(const set<string>::iterator& a, const set<string>::iterator& b) const {
        return *a < *b;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        set<string> uniqueLetters;
        map<set<string>::iterator, size_t, Comparator> positions;
        for(const auto& i : strs) {
            string s = i;
            sort(s.begin(), s.end());
            auto insRes = uniqueLetters.insert(s);
            if(insRes.second) {
                answer.push_back({i});
                positions.insert({insRes.first, answer.size() - 1});
            }
            else {
                answer[positions.at(insRes.first)].push_back(i);
            }
        }
        return answer;
    }
};
