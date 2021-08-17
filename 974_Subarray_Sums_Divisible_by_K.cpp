// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// 
// A subarray is a contiguous part of an array.
// 
//  
// 
// Example 1:
// 
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// Example 2:
// 
// Input: nums = [5], k = 9
// Output: 0
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104
// 

// Explanation
//
// If a subarray is divisible by K, it has to be a multiple of K
// 
// a-b=n*k, a = running total, b = any previous subarray sum, same as original prefix sum problems.
// 
// We want to solve for b, so using basic algebra, b=a-n*k
// 
// We don't know what n is, so we can get rid of n by modding every element by k
// (b%k) = (a%k) - (n*k)%k
// 
// since n*k is a multiple of k and k goes into it evenly, the result of the (n *k)%k will be 0
// 
// therefore
// b%k = a%k
// 
// is the same as the formula we defined earlier, a-b=n*k
// 
// where b = running total, a = any previous subarray sum
// 
// So we just have to see if running total mod k is equal to any previous running total mod k

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> hmap;
        hmap[0] = 1;
        int prefix = 0;
        int res = 0;
        for (int v : nums) {
            prefix = (prefix + v % k + k) % k;
            res += hmap[prefix]++;
        }
        return res;
    }
};