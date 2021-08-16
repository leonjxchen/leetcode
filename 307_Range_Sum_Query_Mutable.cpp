// Given an integer array nums, handle multiple queries of the following types:
// 
// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:
// 
// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
//  
// 
// Example 1:
// 
// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]
// 
// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 104 calls will be made to update and sumRange.

class NumArray {
public:
    NumArray(std::vector<int>& nums) : bits_(nums.size() + 1), data_(nums.size()) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - data_[index];
        for (int i = index + 1; i < bits_.size(); i += (i & -i)) {
            bits_[i] += diff;
        }
        data_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
private:
    int sum(int index) {
        int n = 0;
        for (int i = index; i >= 1; i -= (i & - i)) {
            n += bits_[i];
        }
        return n;
    }
    std::vector<int> bits_;
    std::vector<int> data_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
