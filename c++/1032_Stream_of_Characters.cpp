// Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.
// 
// For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.
// 
// Implement the StreamChecker class:
// 
// StreamChecker(String[] words) Initializes the object with the strings array words.
// boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.
//  
// 
// Example 1:
// 
// Input
// ["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
// [[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
// Output
// [null, false, false, false, true, false, true, false, false, false, false, false, true]
// 
// Explanation
// StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
// streamChecker.query("a"); // return False
// streamChecker.query("b"); // return False
// streamChecker.query("c"); // return False
// streamChecker.query("d"); // return True, because 'cd' is in the wordlist
// streamChecker.query("e"); // return False
// streamChecker.query("f"); // return True, because 'f' is in the wordlist
// streamChecker.query("g"); // return False
// streamChecker.query("h"); // return False
// streamChecker.query("i"); // return False
// streamChecker.query("j"); // return False
// streamChecker.query("k"); // return False
// streamChecker.query("l"); // return True, because 'kl' is in the wordlist
//  
// 
// Constraints:
// 
// 1 <= words.length <= 2000
// 1 <= words[i].length <= 2000
// words[i] consists of lowercase English letters.
// letter is a lowercase English letter.
// At most 4 * 104 calls will be made to query.

struct Trier {
public:
    Trier() : leaf(false), children(26, nullptr) {
        
    }
    bool leaf;
    std::vector<Trier*> children;
};

class StreamChecker {
public:
    StreamChecker(std::vector<std::string>& words) : max_word_size_(0) {
        auto insert = [&](const std::string& s) {
            Trier* ptr = &root_;
            for (char c : s) {
                if (!ptr->children[c - 'a']) {
                    ptr->children[c - 'a'] = new Trier();
                }
                ptr = ptr->children[c - 'a'];
            }
            ptr->leaf = true;
        };
        for (auto& s : words) {
            std::reverse(s.begin(), s.end());
            insert(s);
            max_word_size_ = std::max(s.size(), max_word_size_);
        }
    }
    
    bool query(char letter) {
        query_.push_front(letter);
        if (query_.size() > max_word_size_) {
            query_.pop_back();
        }
        auto check = [&]() -> bool {
            Trier* ptr = &root_;
            for (char c : query_) {
                if (ptr->leaf) {
                    return true;
                }
                if (!ptr->children[c - 'a']) {
                    return false;
                }
                ptr = ptr->children[c - 'a'];
            }
            return ptr->leaf;
        };
        return check();
    }
private:
    Trier root_;
    size_t max_word_size_;
    std::deque<char> query_;
};
