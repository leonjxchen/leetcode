// Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
// 
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
//  
// 
// Example 1:
// 
// Input: s = "abc"
// Output: 7
// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
// Example 2:
// 
// Input: s = "aba"
// Output: 6
// Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "abc".
// Example 3:
// 
// Input: s = "aaa"
// Output: 3
// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
//  
// 
// Constraints:
// 
// 1 <= s.length <= 2000
// s consists of lowercase English letters.

class Solution {
public:
    int distinctSubseqII(std::string s) {
        std::vector<uint64_t> buf(26);
        const int mod = 1e9 + 7;
        for (int i = 0; i < s.size(); ++i) {
            buf[s[i] - 'a'] = std::accumulate(buf.begin(), buf.end(), 1L) % mod;
        }
        return std::accumulate(buf.begin(), buf.end(), 0L) % mod;
    }
};

class Solution {
public:
    int distinctSubseqII(std::string s) {
        std::vector<uint64_t> dp(s.size() + 1);
        dp[0] = 1;
        const int mod = 1e9 + 7;
        std::vector<int> pos(26, -1);
        for (int i = 1; i <= s.size(); ++i) {
            if (pos[s[i - 1] - 'a'] >= 0) {
                dp[i] = ((dp[i - 1] * 2) + mod - dp[pos[s[i - 1] - 'a']]) % mod;
            } else {
                dp[i] = (dp[i - 1] * 2) % mod;
            }
            pos[s[i - 1] - 'a'] = i - 1;
        }
        dp[s.size()]--;
        return dp[s.size()] % mod;
    }
};