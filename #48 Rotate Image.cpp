class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size() / 2; ++i) {
            rotateLevel(matrix, i);
        }
    }

private:
    void rotateLevel(vector<vector<int>>& matrix, size_t level) {
        queue<int> q;
        for (size_t i = matrix.size() - 1 - level; i > level; i--) {
            q.push(matrix[i][level]);
        }
        for (size_t i = level; i < matrix.size() - 1 - level; ++i) {
            q.push(matrix[level][i]);
            matrix[level][i] = q.front();
            q.pop();
        }
        for (size_t i = level; i < matrix.size() - 1 - level; ++i) {
            q.push(matrix[i][matrix.size() - 1 - level]);
            matrix[i][matrix.size() - 1 - level] = q.front();
            q.pop();
        }
        for (size_t i = matrix.size() - 1 - level; i > level; --i) {
            q.push(matrix[matrix.size() - 1 - level][i]);
            matrix[matrix.size() - 1 - level][i] = q.front();
            q.pop();
        }
        for (size_t i = matrix.size() - 1 - level; i > level; --i) {
            matrix[i][level] = q.front();
            q.pop();
        }
    }
};
