// A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
// 
// You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
// 
// Return the minimum number of flips to make s monotone increasing.
// 
//  
// 
// Example 1:
// 
// Input: s = "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
// Example 2:
// 
// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.
// Example 3:
// 
// Input: s = "00011000"
// Output: 2
// Explanation: We flip to get 00000000.
//  
// 
// Constraints:
// 
// 1 <= s.length <= 105
// s[i] is either '0' or '1'.

// Suppose that you have a string s, and the solution to the mono increase question is already solved. That is, for string s, counter_flip flips are required for the string, and there were counter_one '1's in the original string s.
// 
// Let's see the next step of DP.
// 
// Within the string s, a new incoming character, say ch, is appended to the original string. The question is that, how should counter_flip be updated, based on the sub-question? We should discuss it case by case.
// 
// When '1' comes, no more flip should be applied, since '1' is appended to the tail of the original string.
// When '0' comes, things become a little bit complicated. There are two options for us: flip the newly appended '0' to '1', after counter_flip flips for the original string; or flip counter_one '1' in the original string to '0'. Hence, the result of the next step of DP, in the '0' case, is std::min(counter_flip + 1, counter_one);.

class Solution {
public:
    int minFlipsMonoIncr(std::string s) {
        int one = 0;
        int flip = 0;
        for (char c : s) {
            if (c == '1') {
                ++one;
            } else {
                ++flip;
            }
            flip = std::min(flip, one);
        }
        return flip;
    }
};
