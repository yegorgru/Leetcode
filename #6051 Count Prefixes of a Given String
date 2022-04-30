class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int counter = 0;
        for(const auto& word : words) {
            if (s.find(word, 0) == 0) {
                ++counter;
            }
        }
        return counter;
    }
};
