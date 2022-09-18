class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        std::vector<int> res(nums.size());
        int pos[32] = {0};
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = 1;
            for (int j = 0; j < 32; ++j) {
                if ((nums[i] & (1 << j))) {
                    pos[j] = i;
                }
                res[i] = std::max(pos[j] - i + 1, res[i]);
            }
        }
        return res;
    }
};
