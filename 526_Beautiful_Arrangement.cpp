// Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1,2]:
//    - perm[1] = 1 is divisible by i = 1
//    - perm[2] = 2 is divisible by i = 2
// The second beautiful arrangement is [2,1]:
//    - perm[1] = 2 is divisible by i = 1
//    - i = 2 is divisible by perm[2] = 1

class Solution {
public:
    int countArrangement(int n) {
        std::vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            num[i] = i + 1;
        }
        return helper(0, num);
    }
private:
    int helper(int L, std::vector<int>& num) {
        if (L >= num.size()) {
            return 1;
        }
        int res = 0;
        for (int i = L; i < num.size(); ++i) {
            std::swap(num[i], num[L]);
            if (num[L] % (L + 1) == 0 || (L + 1) % num[L] == 0) {
                res += helper(L + 1, num);
            }
            std::swap(num[i], num[L]);
        }
        return res;
    }
};

class Solution {
public:
    int countArrangement(int n) {
        std::vector<int> visited(n, 0);
        return helper(1, visited);
    }
private:
    int helper(int L, std::vector<int>& visited) {
        if (L > visited.size()) {
            return 1;
        }
        int res = 0;
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                if ((i + 1) % L == 0 || L % (i + 1) == 0) {
                    visited[i] = true;
                    res += helper(L + 1, visited);
                    visited[i] = false;
                }
            }
        }
        return res;
    }
};



