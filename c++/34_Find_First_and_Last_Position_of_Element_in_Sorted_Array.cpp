// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
// 
// If target is not found in the array, return [-1, -1].
// 
// You must write an algorithm with O(log n) runtime complexity.
// 
//  
// 
// Example 1:
// 
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
// 
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:
// 
// Input: nums = [], target = 0
// Output: [-1,-1]
//  
// 
// Constraints:
// 
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto helper = [&](int val) -> int {
            int left = 0;
            int right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < val) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };
        int i = helper(target);
        if (i == nums.size() || nums[i] != target) {
            return {-1, -1};
        }
        return {i, helper(target + 1) - 1};
    }
};