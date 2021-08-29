// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// 
// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// 
// It is guaranteed the answer fits on a 32-bit signed integer.
// 
//  
// 
// Example 1:
// 
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit
// Example 2:
// 
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
//  
// 
// Constraints:
// 
// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        std::vector<std::vector<uint64_t>> dp(t.size() + 1, std::vector<uint64_t>(s.size() + 1));
        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if (i > j) {
                    continue;
                }
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + (i == 1);
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};