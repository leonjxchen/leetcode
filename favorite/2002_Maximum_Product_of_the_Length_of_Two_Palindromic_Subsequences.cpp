// Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
// 
// Return the maximum possible product of the lengths of the two palindromic subsequences.
// 
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
// 
//  
// 
// Example 1:
// 
// example-1
// Input: s = "leetcodecom"
// Output: 9
// Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
// The product of their lengths is: 3 * 3 = 9.
// Example 2:
// 
// Input: s = "bb"
// Output: 1
// Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
// The product of their lengths is: 1 * 1 = 1.
// Example 3:
// 
// Input: s = "accbcaxxcxx"
// Output: 25
// Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
// The product of their lengths is: 5 * 5 = 25.
//  
// 
// Constraints:
// 
// 2 <= s.length <= 12
// s consists of lowercase English letters only.

class Solution {
public:
    int maxProduct(std::string s) {
        int dp[4096] = {0};
        auto palindromLength = [&](uint32_t mask) {
            int left = 0;
            int right = s.size() - 1;
            int res = 0;
            while (left <= right) {
                if ((mask & (1 << left)) == 0) {
                    ++left;
                } else if ((mask & (1 << right)) == 0) {
                    --right;
                } else if (s[left] != s[right]) {
                    return 0;
                } else {
                    res += 1 + (left++ != right--);
                }
            }
            return res;
        };
        const int mask = (1 << s.size()) - 1;
        int res = 0;
        for (int i = 1; i < (1 << s.size()); ++i) {
            dp[i] = palindromLength(i);
        }
        for (int i = 0; i < mask; ++i) {
            if (dp[i] <= 0) {
                continue;
            }
            for (int j = i ^ mask; j; j = (j - 1) & (mask ^ i)) {
                res = std::max(res, dp[j] * dp[i]);
            }
        }
        return res;
    }
};