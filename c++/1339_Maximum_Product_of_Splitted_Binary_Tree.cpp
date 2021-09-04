// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
// 
// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
// 
// Note that you need to maximize the answer before taking the mod and not after taking it.
// 
//  
// 
// Example 1:
// 
// 
// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
// Example 2:
// 
// 
// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
// Example 3:
// 
// Input: root = [2,3,9,10,7,8,6,5,4,11,1]
// Output: 1025
// Example 4:
// 
// Input: root = [1,1]
// Output: 1
//  
// 
// Constraints:
// 
// The number of nodes in the tree is in the range [2, 5 * 104].
// 1 <= Node.val <= 104

class Solution {
public:
    int maxProduct(TreeNode* root) {
        int64_t res = 0;
        helper(root, sum(root), res);
        const int64_t mod = 1e9 + 7;
        return res % mod;
    }
private:
    int64_t sum(const TreeNode* root) {
        if (!root) {
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }
    int64_t helper(const TreeNode* root, int64_t n, int64_t& res) {
        if (!root) {
            return 0;
        }
        int64_t left = helper(root->left, n, res);
        int64_t right = helper(root->right, n, res);
        res = std::max({(left * (n - left)), (right * (n - right)), res});
        return left + right + root->val;
    }
};