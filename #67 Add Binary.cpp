class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        for(size_t i = 0; i < max(a.size(), b.size()); i++) {
            if(result.size() < i + 1) {
                result.push_back('0');
            }
            if(i < a.size())
                result.back() += a[a.size() - i - 1] - '0';
            if(i < b.size())
                result.back() += b[b.size() - i - 1] - '0';
            if(result.back() >= '2') {
                result.back() = result.back() - 2;
                result.push_back('1');
            }
        }
        return string(result.rbegin(), result.rend());
    }
};
