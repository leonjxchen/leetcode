class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long res = 0;
        int cost = 0;
        int earn = 0;
        for (int t : transactions) {
            res += std::max(0, t[0] - t[1]);
            if (t[0] > t[1]) {
                cost = std::max(cost, t[1]);
            } else {
                earn = std::max(earn, t[0]);
            }
        }
        return res + std::max(cost, earn);
    }
};
