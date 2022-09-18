// You are given a 0-indexed 2D integer array transactions, where transactions[i] = [costi, cashbacki].
// 
// The array describes transactions, where each transaction must be completed exactly once in some order. At any given moment, you have a certain amount of money. In order to complete transaction i, money >= costi must hold true. After performing a transaction, money becomes money - costi + cashbacki.
// 
// Return the minimum amount of money required before any transaction so that all of the transactions can be completed regardless of the order of the transactions.
// 
//  
// 
// Example 1:
// 
// Input: transactions = [[2,1],[5,0],[4,2]]
// Output: 10
// Explanation:
// Starting with money = 10, the transactions can be performed in any order.
// It can be shown that starting with money < 10 will fail to complete all transactions in some order.
// Example 2:
// 
// Input: transactions = [[3,0],[0,3]]
// Output: 3
// Explanation:
// - If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
// - If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
// Thus, starting with money = 3, the transactions can be performed in any order.
//  
// 
// Constraints:
// 
// 1 <= transactions.length <= 105
// transactions[i].length == 2
// 0 <= costi, cashbacki <= 109

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
