// In this problem, a tree is an undirected graph that is connected and has no cycles.
// 
// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
// 
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
// 
//  
// 
// Example 1:
// 
// 
// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:
// 
// 
// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
//  
// 
// Constraints:
// 
// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

class UnionFind {
public:
    UnionFind(int n) : id_(n), size_(n) {
        for (int i = 0; i < n; ++i) {
            id_[i] = i;
            size_[i] = 1;
        }
    }
    int Root(int i) {
        while (id_[i] != i) {
            id_[i] = id_[id_[i]];
            i = id_[i];
        }
        return i;
    }
    bool Unite(int a, int b) {
        int i = Root(a);
        int j = Root(b);
        if (i == j) {
            return false;
        }
        
        if (size_[i] < size_[j]) {
            id_[i] = j;
            size_[j] += size_[i];
        } else {
            id_[j] = i;
            size_[i] += size_[j];
        }
        return true;
    }
private:
    std::vector<int> id_;
    std::vector<int> size_;
};

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        UnionFind finder(edges.size() + 1);
        for (const auto& v : edges) {
            if (!finder.Unite(v[0], v[1])) {
                return v;
            }
        }
        return {};
    }
};