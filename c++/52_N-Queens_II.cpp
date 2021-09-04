// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// 
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
// 
//  
// 
// Example 1:
// 
// 
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:
// 
// Input: n = 1
// Output: 1
//  
// 
// Constraints:
// 
// 1 <= n <= 9

class Solution {
public:
    int totalNQueens(int n) {
        std::vector<std::string> res(n, std::string(n, '.'));
        return helper(res, 0);
    }
private:
    int helper(std::vector<std::string>& res, int x) {
        if (x >= res.size()) {
            return 1;
        }
        int cnt = 0;
        for (int i = 0; i < res.size(); ++i) {
            if (check(res, x, i)) {
                res[x][i] = 'Q';
                cnt += helper(res, x + 1);
                res[x][i] = '.';
            }
        }
        return cnt;
    }
    bool check(std::vector<std::string>& res, int x, int y) {
        for (int r = x - 1, c = y; r >= 0; --r) {
            if (res[r][c] == 'Q') {
                return false;
            }
        }
        for (int r = x - 1, c = y + 1; r >= 0 && c < res.size(); --r, ++c) {
            if (res[r][c] == 'Q') {
                return false;
            }
        }
        for (int r = x - 1, c = y - 1; r >= 0 && c >= 0; --r, --c) {
            if (res[r][c] == 'Q') {
                return false;
            }
        }
        return true;
    }
};