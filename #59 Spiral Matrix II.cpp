class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1) {
            return {{1}};
        }
        vector<vector<int>> matrix(n, vector<int>(n));
        mFlags.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(size_t i = 0; i <= min(matrix.size() - 1, matrix[0].size() - 1) / 2; i++) {
            walkRight(matrix, i);
            walkDown(matrix, i);
            walkLeft(matrix, i);
            walkTop(matrix, i);
        }
        return matrix;
    }
    
private:
    int walkRight(vector<vector<int>>& matrix, size_t padding) {
        int res = 0;
        for(size_t i = padding; i < matrix[0].size() - padding; i++, res++) {
            if(!mFlags[padding][i]) {
                matrix[padding][i] = ++mCurrNumber;
                mFlags[padding][i] = true;
            }
        }
        return res;
    }
    
    int walkLeft(vector<vector<int>>& matrix, size_t padding) {
        int res = 0;
        size_t x = matrix.size() - 1 - padding;
        for(size_t i = matrix[0].size() - 1 - padding; i >= padding; i--, res++) {
            if(!mFlags[x][i]) {
                matrix[x][i] = ++mCurrNumber;
                mFlags[x][i] = true;
            }
            if(i == padding) {
                res++;
                break;
            }
        }
        return res;
    }
    
    int walkDown(vector<vector<int>>& matrix, size_t padding) {
        int res = 0;
        size_t y = matrix[0].size() - 1 - padding;
        for(size_t i = padding + 1; i < matrix.size() - 1 - padding; i++, res++) {
            if(!mFlags[i][y]) {
                matrix[i][y] = ++mCurrNumber;
                mFlags[i][y] = true;
            }
        }
        return res;
    }
    
    int walkTop(vector<vector<int>>& matrix, size_t padding) {
        int res = 0;
        for(size_t i = matrix.size() - 2 - padding; i > padding; i--, res++) {
            if(!mFlags[i][padding]) {
                matrix[i][padding] = ++mCurrNumber;
                mFlags[i][padding] = true;
            }
            if(i == 0) {
                res++;
                break;
            }
        }
        return res;
    }
    
    vector<vector<bool>> mFlags;
    int mCurrNumber;
};
