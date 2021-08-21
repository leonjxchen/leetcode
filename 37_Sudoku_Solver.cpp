// Write a program to solve a Sudoku puzzle by filling the empty cells.
// 
// A sudoku solution must satisfy all of the following rules:
// 
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.
// 
//  
// 
// Example 1:
// 
// 
// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:
// 
// 
//  
// 
// Constraints:
// 
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<bool>> row(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> col(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> block(9, std::vector<bool>(9, false));
        std::vector<int> pos;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    pos.push_back(i * 10 + j);
                } else {
                    int d = board[i][j] - '1';
                    int idx = (i / 3) * 3 + j / 3;
                    row[i][d] = true;
                    col[j][d] = true;
                    block[idx][d] = true;
                }
            }
        }
        helper(0, pos, board, row, col, block);
    }
private:
    bool helper(
        int i,
        std::vector<int>& pos,
        std::vector<std::vector<char>>& board,
        std::vector<std::vector<bool>>& row,
        std::vector<std::vector<bool>>& col,
        std::vector<std::vector<bool>>& block) {
        if (i >= pos.size()) {
            return true;
        }
        int x = pos[i] / 10;
        int y = pos[i] % 10;
        int idx = (x / 3) * 3 + y / 3;
        for (char c = '1'; c <= '9'; ++c) {
            if (row[x][c - '1'] || col[y][c - '1'] || block[idx][c - '1']) {
                continue;
            }
            row[x][c - '1'] = true;
            col[y][c - '1'] = true;
            block[idx][c - '1'] = true;
            board[x][y] = c;
            if (helper(i + 1, pos, board, row, col, block)) {
                return true;
            }
            row[x][c - '1'] = false;
            col[y][c - '1'] = false;
            block[idx][c - '1'] = false;
            board[x][y] = '.';
        }
        return false;
    }
};