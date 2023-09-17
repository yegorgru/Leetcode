class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            spreadM(board, i, 0);  
            spreadM(board, i, board.back().size() - 1);
        }
        for(int j = 0; j < board.back().size(); ++j) {
            spreadM(board, 0, j);  
            spreadM(board, board.size() - 1, j);
        }
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board.back().size(); ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void spreadM(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board.back().size() || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'M';
        spreadM(board, i - 1, j);
        spreadM(board, i + 1, j);
        spreadM(board, i, j - 1);
        spreadM(board, i, j + 1);
    }
};
