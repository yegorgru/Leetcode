class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        map<char, int> f;
        for (auto ch : s) {
            ++f[ch];
        }
        if (f.size() < k) {
            return 0;
        }
        vector<pair<char, int>> fv(f.begin(), f.end());
        sort(fv.begin(), fv.end(), [](const pair<char, int>& lhs, const pair<char, int>& rhs) {
            return lhs.second < rhs.second;
            });
        auto bound = fv[fv.size() - k];
        int leftBoundIdx = fv.size() - k;
        while (leftBoundIdx >= 0 && fv[leftBoundIdx].second == bound.second) {
            --leftBoundIdx;
        }
        ++leftBoundIdx;
        int rightBoundIdx = fv.size() - k;
        while (rightBoundIdx < fv.size() && fv[rightBoundIdx].second == bound.second) {
            ++rightBoundIdx;
        }
        unsigned long long result = 1;
        int m = 0;
        for (size_t i = rightBoundIdx; i < fv.size(); ++i) {
            result *= fv[i].second;
            result %= (1'000'000'000 + 7);
            ++m;
        }
        for (int i = 0; i < k - m; ++i) {
            result *= bound.second;
            result %= (1'000'000'000 + 7);
        }
        for (int i = k - m + 1; i <= rightBoundIdx - leftBoundIdx; ++i) {
            result *= i;
        }
        int last = rightBoundIdx - leftBoundIdx - (k - m);
        result /= fact(last);
        return int(result % (1'000'000'000 + 7));
    }

private:
    unsigned long long fact(int n) {
        if (n < 1) {
            return 1;
        }
        else {
            return n * fact(n - 1);
        }
    }
};
