#include <vector>
#include <string>

// "Sudoku Solver"

//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        init(board);
        solveSudoku(board, 0, 0);
    }

private:    
    bool solveSudoku(std::vector<std::vector<char>>& board, size_t row, size_t col) {
        std::string digits = "123456789";
        size_t nextRow = col == 8 ? row + 1 : row;
        size_t nextCol = col == 8 ? 0 : col + 1;
        if(board[row][col] != '.') {
            if(row == 8 && col == 8) {
                return true;
            }
            else {
                return solveSudoku(board, nextRow, nextCol);
            }
        }
        for(auto digit : digits) {
            size_t number = digit - 49;
            if(mRows[row][number] || mCols[col][number] || mSubBoxes[row/3][col/3][number]) {
                continue;
            }
            board[row][col] = digit;
            if(row == 8 && col == 8) {
                return true;
            }
            mRows[row][number] = true;
            mCols[col][number] = true;
            mSubBoxes[row/3][col/3][number] = true;
            if(solveSudoku(board, nextRow, nextCol)){
                return true;
            }
            mRows[row][number] = false;
            mCols[col][number] = false;
            mSubBoxes[row/3][col/3][number] = false;
        }
        board[row][col] = '.';
        return false;
    }
        
    void init(std::vector<std::vector<char>>& board) {
        mSubBoxes.resize(3, std::vector<std::vector<bool>>(3, std::vector<bool>(9, false)));
        mRows.resize(9, std::vector<bool>(9, false));
        mCols.resize(9, std::vector<bool>(9, false));
        for(size_t i= 0; i < board.size(); i++) {
            for(size_t j= 0; j < board.at(i).size(); j++) {
                if(board[i][j] != '.') {
                    size_t number = board[i][j] - 49;
                    mRows[i][number] = true;
                    mCols[j][number] = true;
                    mSubBoxes[i/3][j/3][number] = true;
                }
            }
        }
    }
    
private:
    std::vector<std::vector<bool>> mRows;
    std::vector<std::vector<bool>> mCols;
    std::vector<std::vector<std::vector<bool>>> mSubBoxes;
};
