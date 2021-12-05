// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
// 
// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
// 
// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
// 
//  
// 
// Example 1:
// 
// 
// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
// 
// 
// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
//  
// 
// Constraints:
// 
// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104

class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = rob(root->left);
        int right = rob(root->right);
        auto res = helper(root);
        return std::max(res[0], res[1]);
    }
private:
    std::vector<int> helper(const TreeNode* root) {
        if (!root) {
            return std::vector<int>(2);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        std::vector<int> tmp(2);
        tmp[0] = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        tmp[1] = root->val + left[0] + right[0];
        return tmp;
    }
};
