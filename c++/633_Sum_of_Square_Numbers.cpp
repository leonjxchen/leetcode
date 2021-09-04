// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
// 
//  
// 
// Example 1:
// 
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:
// 
// Input: c = 3
// Output: false
// Example 3:
// 
// Input: c = 4
// Output: true
// Example 4:
// 
// Input: c = 2
// Output: true
// Example 5:
// 
// Input: c = 1
// Output: true
//  
// 
// Constraints:
// 
// 0 <= c <= 231 - 1

class Solution {
public:
    bool judgeSquareSum(int c) {
        uint64_t a = helper(c);
        if (a * a == c) {
          return true;
        }
        uint64_t left = 1;
        uint64_t right = a;
        while (left <= right) {
          uint64_t n = left * left + right * right;
          if (n < c) {
            ++left;
          } else if (n > c) {
            --right;
          } else {
            return true;
          }
        }
        return false;
    }
private:
    int helper(int c) {
      uint64_t left = 0;
      uint64_t right = c;
      while (left < right) {
        uint64_t mid = left + (right - left) / 2;
        if (mid * mid < c) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return left;
    }
};