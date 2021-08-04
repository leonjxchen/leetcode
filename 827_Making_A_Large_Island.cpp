class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        std::vector<int> s(2, 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    s.push_back(helper(grid, i, j, s.size()));
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> hset;
                    int area = 1;
                    for (int k = 0; k < kDIR.size() - 1; ++k) {
                        int x = i + kDIR[k];
                        int y = j + kDIR[k + 1];
                        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size()) {
                            continue;
                        }
                        hset.insert(grid[x][y]);
                    }
                    for (int v : hset) {
                        area += s[v];
                    }
                    res = std::max(res, area);
                }
            }
        }
        return res == 0 ? grid.size() * grid[0].size() : res;
    }
private:
    int helper(std::vector<std::vector<int>>& grid, int x, int y, int val) {
        if (x < 0 || y < 0 || x >= grid.size() || 
            y >= grid[x].size() || grid[x][y] == val || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = val;
        int res = 1;
        for (int i = 0; i < kDIR.size() - 1; ++i) {
            int j = x + kDIR[i];
            int k = y + kDIR[i + 1];
            res += helper(grid, j, k, val);
        }
        return res;
    }
    const std::vector<int> kDIR = {0, -1, 0, 1, 0};
};
