#include <vector>

//Determine if a 9 x 9 Sudoku board is valid

//https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    /*bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<bool>> rows(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> cols(9, std::vector<bool>(9, false));
        std::vector<std::vector<std::vector<bool>>> subBoxes;
        subBoxes.resize(3, std::vector<std::vector<bool>>(3, std::vector<bool>(9, false)));
        for(size_t i = 0; i < 9; i++) {
            for(size_t j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    size_t number = board[i][j] - 49;
                    if(rows[i][number] || cols[j][number] || subBoxes[i/3][j/3][number]) {
                        return false;
                    }
                    else {
                        rows[i][number] = true;
                        cols[j][number] = true;
                        subBoxes[i/3][j/3][number] = true;
                    }
                }
            }
        }
        return true;
    }*/
    
    98.77
    
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::set<char>> rows(9);
        std::vector<std::set<char>> cols(9);
        std::vector<std::vector<std::set<char>>> subBoxes(3, std::vector<std::set<char>>(3));
        for(size_t i = 0; i < 9; i++) {
            for(size_t j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    //if(rows[i].contains(board[i][j]) != || cols[j].contains(board[i][j]) || subBoxes[box].contains(board[i][j]))
                    if(rows[i].find(board[i][j]) != rows[i].end() || 
                       cols[j].find(board[i][j]) != cols[j].end() || 
                       subBoxes[i/3][j/3].find(board[i][j]) != subBoxes[i/3][j/3].end()) {
                        return false;
                    }
                    else {
                        rows[i].insert(board[i][j]);
                        cols[j].insert(board[i][j]);
                        subBoxes[i/3][j/3].insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
    
    /*bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::set<char>> rows(9);
        std::vector<std::set<char>> cols(9);
        std::vector<std::vector<std::set<char>>> boxes(3, std::vector<std::set<char>>(3));
        for(size_t i = 0; i < 9; i++) {
            for(size_t j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    auto rowsFound = rows[i].lower_bound(board[i][j]);
                    auto colsFound = cols[j].lower_bound(board[i][j]);
                    auto boxesFound = boxes[i/3][j/3].lower_bound(board[i][j]);
                    if(rowsFound != rows[i].end() && *rowsFound == board[i][j] || 
                       colsFound != cols[j].end() && *colsFound == board[i][j] || 
                       boxesFound != boxes[i/3][j/3].end() && *boxesFound == board[i][j]) {
                        return false;
                    }
                    else {
                        rows[i].insert(rowsFound, board[i][j]);
                        cols[j].insert(colsFound, board[i][j]);
                        boxes[i/3][j/3].insert(boxesFound, board[i][j]);
                    }
                }
            }
        }
        return true;
    }*/
};
