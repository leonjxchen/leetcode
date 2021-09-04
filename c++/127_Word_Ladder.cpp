// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::queue<std::string> q;
        std::unordered_set<std::string> hset(wordList.begin(), wordList.end());
        if (hset.find(endWord) == hset.end()) {
            return 0;
        }
        int cnt = 1;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                std::string v = q.front();
                q.pop();
                for (int i = 0; i < v.size(); ++i) {
                    char c = v[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        v[i] = j;
                        if (hset.find(v) != hset.end()) {
                            if (v == endWord) {
                                return cnt + 1;
                            }
                            q.push(v);
                            hset.erase(v);
                        }
                        
                        v[i] = c;
                    }
                }
            }
            ++cnt;
        }
        return 0;
    }
};


class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> hset(wordList.begin(), wordList.end());
        std::unordered_set<std::string> front{beginWord};
        std::unordered_set<std::string> end{endWord};
        if (hset.find(endWord) == hset.end()) {
            return 0;
        }
        int cnt = 2;
        while (!front.empty() && !end.empty()) {
            if (front.size() > end.size()) {
                std::swap(front, end);
            }
            std::unordered_set<std::string> s;
            for (std::string v : front) {
                for (int i = 0; i < v.size(); ++i) {
                    char c = v[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        v[i] = j;
                        if (end.find(v) != end.end()) {
                            return cnt;
                        }
                        
                        if (hset.find(v) != hset.end()) {
                            s.insert(v);
                            hset.erase(v);
                        }
                        v[i] = c;
                    }
                }
            }
            ++cnt;
            std::swap(s, front);
        }
        return 0;
    }
};