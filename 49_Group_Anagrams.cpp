// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// 
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// 
//  
// 
// Example 1:
// 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:
// 
// Input: strs = [""]
// Output: [[""]]
// Example 3:
// 
// Input: strs = ["a"]
// Output: [["a"]]
//  
// 
// Constraints:
// 
// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> hmap;
        for (auto& s : strs) {
            auto v = s;
            std::sort(v.begin(), v.end());
            hmap[v].push_back(std::move(s));
        }
        for (auto& [k, v] : hmap) {
            res.push_back(std::move(v));
        }
        return res;
    }
};