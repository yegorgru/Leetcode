class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 1) {
            vector<vector<int>> result(n);
            for (int i = 1; i <= n; ++i) {
                result[i - 1] = {i};
            }
            return result;
        }
        else if(n == k) {
            vector<vector<int>> result(1, vector<int>(n));
            for (int i = 1; i <= n; ++i) {
                result[0][i - 1] = i;
            }
            return result;
        }
        else {
            auto result = combine(n - 1, k);
            auto withoutCurrent = combine(n - 1, k - 1);
            result.reserve(result.size() + withoutCurrent.size());
            for(auto& v : withoutCurrent) {
                v.push_back(n);
                result.push_back(move(v));
            }
            return result;
        }
    }

private:
    vector<vector<int>> combinations;
};
