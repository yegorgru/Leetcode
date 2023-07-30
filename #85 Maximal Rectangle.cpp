class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        maxLinesMatrix = MaxLinesMatrix(matrix.size(), MaxLinesRow(matrix[0].size(), make_pair(0, 0)));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i == 0) {
                    maxLinesMatrix[i][j].first = isOne(matrix, i, j);
                }
                else {
                    maxLinesMatrix[i][j].first = isOne(matrix, i, j) * maxLinesMatrix[i - 1][j].first + isOne(matrix, i, j);
                }
                if (j == 0) {
                    maxLinesMatrix[i][j].second = isOne(matrix, i, j);
                }
                else {
                    maxLinesMatrix[i][j].second = isOne(matrix, i, j) * maxLinesMatrix[i][j-1].second + isOne(matrix, i, j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (isOne(matrix, i, j)) {
                    maxArea = max(maxArea, evaluateArea(matrix, i, j));
                }
            }
        }
        return maxArea;
    }

private:
    bool isOne(const vector<vector<char>>& matrix, int i, int j) {
        return matrix[i][j] == '1';
    }

    int evaluateArea(const vector<vector<char>>& matrix, int i, int j) {
        int result = max(maxLinesMatrix[i][j].first, maxLinesMatrix[i][j].second);
        int horizontal = maxLinesMatrix[i][j].second;
        int currI = i - 1;
        while (currI >= 0 && isOne(matrix, currI, j)) {
            horizontal = min(horizontal, maxLinesMatrix[currI][j].second);
            result = max(result, horizontal * (i - currI + 1));
            --currI;
        }
        int vertical = maxLinesMatrix[i][j].first;
        int currJ = j - 1;
        while (currJ >= 0 && isOne(matrix, i, currJ)) {
            vertical = min(vertical, maxLinesMatrix[i][currJ].first);
            result = max(result, vertical * (j - currJ + 1));
            --currJ;
        }
        return result;
    }

private:
    using MaxLines = pair<int, int>;
    using MaxLinesRow = vector<MaxLines>;
    using MaxLinesMatrix = vector<MaxLinesRow>;
    MaxLinesMatrix maxLinesMatrix;
    int maxArea = 0;
};
