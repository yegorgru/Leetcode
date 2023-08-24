class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) {
            return {1};
        }
        else {
            auto prev = getRow(rowIndex - 1);
            vector<int> next(rowIndex + 1, 1);
            for(size_t i = 1; i < rowIndex; ++i) {
                next[i] = prev[i - 1] + prev[i];
            }
            return next;
        }
    }
};
