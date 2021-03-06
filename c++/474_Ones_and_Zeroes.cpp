// You are given an array of binary strings strs and two integers m and n.
// 
// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// 
// A set x is a subset of a set y if all elements of x are also elements of y.
// 
//  
// 
// Example 1:
// 
// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
// Example 2:
// 
// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.
//  
// 
// Constraints:
// 
// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (const auto& s : strs) {
            int ones = 0;
            int zeros = 0;
            for (char c : s) {
                if (c == '1') {
                    ++ones;
                } else {
                    ++zeros;
                }
            }
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = std::max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        std::vector<std::vector<std::vector<int>>> dp(strs.size() + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1)));
        for (int i = 1; i <= strs.size(); ++i) {
            int ones = std::count(strs[i - 1].begin(), strs[i - 1].end(), '1');
            int zeros = strs[i - 1].size() - ones;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};