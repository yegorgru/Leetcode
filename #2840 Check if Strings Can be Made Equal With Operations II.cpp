class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string evenStr1;
        string oddStr1;
        string evenStr2;
        string oddStr2;
        evenStr1.reserve(s1.size() / 2 + 1);
        oddStr1.reserve(s1.size() / 2 + 1);
        evenStr2.reserve(s1.size() / 2 + 1);
        oddStr2.reserve(s1.size() / 2 + 1);
        for(size_t i = 0; i < s1.size(); ++i) {
            if(i % 2 == 0) {
                evenStr1.push_back(s1[i]);
                evenStr2.push_back(s2[i]);
            }
            else {
                oddStr1.push_back(s1[i]);
                oddStr2.push_back(s2[i]);
            }
        }
        sort(evenStr1.begin(), evenStr1.end());
        sort(oddStr1.begin(), oddStr1.end());
        sort(evenStr2.begin(), evenStr2.end());
        sort(oddStr2.begin(), oddStr2.end());
        return evenStr1 == evenStr2 && oddStr1 == oddStr2;
    }
};
