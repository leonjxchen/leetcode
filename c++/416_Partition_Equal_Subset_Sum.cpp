// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:
// 
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int n = sum / 2;
        std::vector<int> dp(sum / 2 + 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = n; j >= nums[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[n] == n;
    }
};