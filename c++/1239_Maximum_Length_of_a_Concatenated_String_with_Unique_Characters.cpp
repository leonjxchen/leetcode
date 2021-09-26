// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
// 
// Return the maximum possible length of s.
// 
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//  
// 
// Example 1:
// 
// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are "","un","iq","ue","uniq" and "ique".
// Maximum length is 4.
// Example 2:
// 
// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible solutions are "chaers" and "acters".
// Example 3:
// 
// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
//  
// 
// Constraints:
// 
// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lower case English letters.

class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<uint32_t> vec(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            int mask = 0;
            for (char c : arr[i]) {
                if (mask & (1 << (c - 'a'))) {
                    mask = -1;
                    break;
                }
                mask |= (1 << (c - 'a'));
            }
            if (mask != -1) {
                vec[i] = mask;
            }
        }
        return dfs(0, 0, vec);
    }
private:
    int dfs(int index, uint32_t mask, const std::vector<uint32_t>& vec) {
        if (index >= vec.size()) {
            return count(mask);
        }
        std::cout << mask << std::endl;
        int len = count(mask);
        for (int i = index; i < vec.size(); ++i) {
            if ((mask & vec[i]) == 0) {
                len = std::max(dfs(i + 1, mask | vec[i], vec), len);
            }
        }
        return len;
    }
    int count(uint32_t mask) {
        int cnt = 0;
        while (mask) {
            ++cnt;
            mask &= (mask - 1);
        }
        return cnt;
    }
};
