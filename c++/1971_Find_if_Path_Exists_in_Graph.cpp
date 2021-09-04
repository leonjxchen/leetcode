// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
// 
// You want to determine if there is a valid path that exists from vertex start to vertex end.
// 
// Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.
// 
//  
// 
// Example 1:
// 
// 
// Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2
// Example 2:
// 
// 
// Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
// Output: false
// Explanation: There is no path from vertex 0 to vertex 5.
//  
// 
// Constraints:
// 
// 1 <= n <= 2 * 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 1 <= ui, vi <= n - 1
// ui != vi
// 1 <= start, end <= n - 1
// There are no duplicate edges.
// There are no self edges.

class QuickFind {
public:
    QuickFind(int n) : size_(n, 1) {
        for (int i = 0; i < n; ++i) {
            node_.push_back(i);
        }
    }
    int find(int a) {
       while(node_[a] != a) {
           node_[a] = node_[node_[a]];
           a = node_[a];
       }
       return a;
    }
    void unite(int a, int b) {
        int i = find(a);
        int j = find(b);
        if (i == j) {
            return;
        }
        if (size_[i] < size_[j]) {
            node_[i] = j;
            size_[j] += size_[i];
        } else {
            node_[j] = i;
            size_[i] += size_[j];
        }
    }
private:
    std::vector<int> node_;
    std::vector<int> size_;
};

class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int start, int end) {
        QuickFind q(n);
        for (const auto& e : edges) {
            q.unite(e[0], e[1]);
        }
        return q.find(start) == q.find(end);
    }
};