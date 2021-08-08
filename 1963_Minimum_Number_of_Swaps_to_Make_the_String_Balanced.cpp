// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
// 
// A string is called balanced if and only if:
// 
// It is the empty string, or
// It can be written as AB, where both A and B are balanced strings, or
// It can be written as [C], where C is a balanced string.
// You may swap the brackets at any two indices any number of times.
// 
// Return the minimum number of swaps to make s balanced.
// 
//  
// 
// Example 1:
// 
// Input: s = "][]["
// Output: 1
// Explanation: You can make the string balanced by swapping index 0 with index 3.
// The resulting string is "[[]]".
// Example 2:
// 
// Input: s = "]]][[["
// Output: 2
// Explanation: You can do the following to make the string balanced:
// - Swap index 0 with index 4. s = "[]][[]".
// - Swap index 1 with index 5. s = "[[][]]".
// The resulting string is "[[][]]".
// Example 3:
// 
// Input: s = "[]"
// Output: 0
// Explanation: The string is already balanced.
//  
// 
// Constraints:
// 
// n == s.length
// 2 <= n <= 106
// n is even.
// s[i] is either '[' or ']'.
// The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

// Explanation
// The idea is to traverse our string and check the biggest possible disbalance. For example if we look at ]]][]]][[[[[, for traversals we have:
// -1, -2, -3, -2, -3, -4, -5, -4, -3, -2, -1, 0 and the biggest disbalance is equal to 5. What we can do in one swap of brackets is to decreas it at most by 2: for this we need to take the leftest ] with negative balance and the rightest [ with negative balance and change them. For example in our case we have:
// 
// []][]]][[[[] : [1, 0, -1, 0, -1, -2, -3, -2, -1, 0, 1, 0]
// 
// [][[]]][][[] : [1, 0, 1, 2, 1, 0, -1, 0, -1, 0, 1, 0]
// 
// [][[]][[]][] : [1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0]
// 
// Complexity
// Time complexity is O(n) to traverse our string, space is O(1).

class Solution {
public:
    int minSwaps(std::string s) {
        int res = 0;
        int val = 0;
        for (char c : s) {
            if (c == '[') {
                ++val;
            } else {
                --val;
            }
            res = std::min(res, val);
        }
        return (-res + 1) / 2;
    }
};
