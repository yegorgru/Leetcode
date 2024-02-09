class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) {
            return {{1}};
        }
        else {
            auto prev = generate(numRows - 1);
            vector<int> next(numRows, 1);
            for(size_t i = 1; i < numRows - 1; ++i) {
                next[i] = prev[numRows - 2][i - 1] + prev[numRows - 2][i];
            }
            prev.push_back(next);
            return prev;
        }
    }
};
