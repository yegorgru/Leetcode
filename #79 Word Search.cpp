class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        wordSize = word.size();
        positions = vector<vector<set<size_t>>>(board.size(), vector<set<size_t>>(board[0].size()));
        vector<pair<size_t, size_t>> startPoints;
        for (size_t k = 0; k < word.size(); ++k) {
            for (size_t i = 0; i < board.size(); ++i) {
                for (size_t j = 0; j < board[0].size(); ++j) {
                    if (word[k] == board[i][j]) {
                        positions[i][j].insert(positions[i][j].end(), k);
                        if (k == 0) {
                            startPoints.push_back(make_pair(i, j));
                        }
                    }
                }
            }
        }
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (auto startPoint : startPoints) {
            if (exist(used, startPoint.first, startPoint.second, 1)) {
                return true;
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<bool>>& used, size_t i, size_t j, size_t currentPos) {
        if (currentPos == wordSize) {
            return true;
        }
        used[i][j] = true;
        if (i > 0 && !used[i - 1][j] && positions[i - 1][j].count(currentPos)) {
            if (exist(used, i - 1, j, currentPos + 1)) {
                return true;
            }
        }
        if (i < used.size() - 1 && !used[i + 1][j] && positions[i + 1][j].count(currentPos)) {
            if (exist(used, i + 1, j, currentPos + 1)) {
                return true;
            }
        }
        if (j > 0 && !used[i][j - 1] && positions[i][j - 1].count(currentPos)) {
            if (exist(used, i, j - 1, currentPos + 1)) {
                return true;
            }
        }
        if (j < used[0].size() - 1 && !used[i][j + 1] && positions[i][j + 1].count(currentPos)) {
            if (exist(used, i, j + 1, currentPos + 1)) {
                return true;
            }
        }
        used[i][j] = false;
        return false;
    }

private:
    size_t wordSize = 0;
    vector<vector<set<size_t>>> positions;
};
