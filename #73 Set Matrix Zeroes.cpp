class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for(size_t i = 0; i < matrix.size(); ++i) {
            for(size_t j = 0; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto row : rows) {
            for (size_t j = 0; j < matrix[row].size(); ++j) {
                matrix[row][j] = 0;
            }
        }
        for (auto col : cols) {
            for (size_t i = 0; i < matrix.size(); ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};
