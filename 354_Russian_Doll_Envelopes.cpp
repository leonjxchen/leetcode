// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
// 
// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
// 
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// 
// Note: You cannot rotate an envelope.
// 
//  
// 
// Example 1:
// 
// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
// Example 2:
// 
// Input: envelopes = [[1,1],[1,1],[1,1]]
// Output: 1
//  
// 
// Constraints:
// 
// 1 <= envelopes.length <= 5000
// envelopes[i].length == 2
// 1 <= wi, hi <= 104

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& A) {
        std::sort(A.begin(), A.end(), 
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      if (a[0] < b[0]) {
                          return true;
                      } else if (a[0] == b[0] && a[1] > b[1]) {
                          return true;
                      }
                      return false;
                  });
        std::vector<int> vec;
        for (int i = 0; i < A.size(); ++i) {
            if (vec.empty() || vec.back() < A[i][1]) {
                vec.push_back(A[i][1]);
                continue;
            }
            int left = 0;
            int right = vec.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (vec[mid] < A[i][1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            vec[left] = A[i][1];
        }
        return vec.size();
    }
};
