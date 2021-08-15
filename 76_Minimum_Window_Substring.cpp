// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// 
// The testcases will be generated such that the answer is unique.
// 
// A substring is a contiguous sequence of characters within the string.
// 
//  
// 
// Example 1:
// 
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:
// 
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:
// 
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
//  
// 
// Constraints:
// 
// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
//  
// 
// Follow up: Could you find an algorithm that runs in O(m + n) time?

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int left = 0;
        int right = 0;
        int buf[128] = {0};
        int win[128] = {0};
        int total = 0;
        int cnt = 0;
        int len = INT_MAX;
        std::string res;
        for (char c : t) {
            if (win[c]++ == 0) {
                ++total;
            }
        }
        while (right < s.size()) {
            char c = s[right++];
            if (++buf[c] == win[c]) {
                ++cnt;
            }
            
            while (cnt == total && left <= right) {
                if (right - left < len) {
                    res = s.substr(left, right - left);
                    len = res.size();
                }
                c = s[left++];
                if (win[c] != 0 && buf[c]-- == win[c]) {
                    --cnt;
                }
            }
        }
        return res;
    }
};