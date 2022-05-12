class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 1) {
            return matrix[0];
        }
        vector<int> answer;
        mFlags.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
        answer.reserve(matrix.size() * matrix[0].size());
        for(size_t i = 0; i <= min(matrix.size() - 1, matrix[0].size() - 1) / 2; i++) {
            walkRight(matrix, answer, i);
            walkDown(matrix, answer, i);
            walkLeft(matrix, answer, i);
            walkTop(matrix, answer, i);
        }
        return answer;
    }
    
private:
    int walkRight(const vector<vector<int>>& matrix, vector<int>& answer, size_t padding) {
        int res = 0;
        for(size_t i = padding; i < matrix[0].size() - padding; i++, res++) {
            if(!mFlags[padding][i]) {
                answer.push_back(matrix[padding][i]);
                mFlags[padding][i] = true;
            }
        }
        return res;
    }
    
    int walkLeft(const vector<vector<int>>& matrix, vector<int>& answer, size_t padding) {
        int res = 0;
        size_t x = matrix.size() - 1 - padding;
        for(size_t i = matrix[0].size() - 1 - padding; i >= padding; i--, res++) {
            if(!mFlags[x][i]) {
                answer.push_back(matrix[x][i]);
                mFlags[x][i] = true;
            }
            if(i == padding) {
                res++;
                break;
            }
        }
        return res;
    }
    
    int walkDown(const vector<vector<int>>& matrix, vector<int>& answer, size_t padding) {
        int res = 0;
        size_t y = matrix[0].size() - 1 - padding;
        for(size_t i = padding + 1; i < matrix.size() - 1 - padding; i++, res++) {
            if(!mFlags[i][y]) {
                answer.push_back(matrix[i][y]);
                mFlags[i][y] = true;
            }
        }
        return res;
    }
    
    int walkTop(const vector<vector<int>>& matrix, vector<int>& answer, size_t padding) {
        int res = 0;
        for(size_t i = matrix.size() - 2 - padding; i > padding; i--, res++) {
            if(!mFlags[i][padding]) {
                answer.push_back(matrix[i][padding]);
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
};
