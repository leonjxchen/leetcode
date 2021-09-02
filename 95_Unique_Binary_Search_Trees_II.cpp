// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// 
//  
// 
// Example 1:
// 
// 
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:
// 
// Input: n = 1
// Output: [[1]]
//  
// 
// Constraints:
// 
// 1 <= n <= 8

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n + 1);
    }
private:
    std::vector<TreeNode*> dfs(int left, int right) {
        std::vector<TreeNode*> res;
        if (left >= right) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = left; i < right; ++i) {
            std::vector<TreeNode*> L = dfs(left, i);
            std::vector<TreeNode*> R = dfs(i + 1, right);
            for (auto* j : L) {
                for (auto* k : R) {
                    TreeNode* root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};