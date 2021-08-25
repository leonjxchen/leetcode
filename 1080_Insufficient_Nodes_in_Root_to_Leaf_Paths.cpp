// Given the root of a binary tree and an integer limit, delete all insufficient nodes in the tree simultaneously, and return the root of the resulting binary tree.
// 
// A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.
// 
// A leaf is a node with no children.
// 
//  
// 
// Example 1:
// 
// 
// Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
// Output: [1,2,3,4,null,null,7,8,9,null,14]
// Example 2:
// 
// 
// Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
// Output: [5,4,8,11,null,17,4,7,null,null,null,5]
// Example 3:
// 
// 
// Input: root = [1,2,-3,-5,null,4,null], limit = -1
// Output: [1,null,-3,4]
//  
// 
// Constraints:
// 
// The number of nodes in the tree is in the range [1, 5000].
// -105 <= Node.val <= 105
// -109 <= limit <= 109

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root, 0, limit);
    }
private:
    TreeNode* helper(TreeNode* root, int sum, int limit) {
        if (!root) {
            return root;
        }
        if (!root->left && !root->right) {
            if (sum + root->val < limit) {
                //delete root;
                return nullptr;
            }
            return root;
        }
        root->left = helper(root->left, sum + root->val, limit);
        root->right = helper(root->right, sum + root->val, limit);
        if (!root->left && !root->right) {
            //delete root;
            return nullptr;
        }
        return root;
    }
};