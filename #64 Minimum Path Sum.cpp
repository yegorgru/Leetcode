class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(auto it = next(grid.rbegin()); it < grid.rend(); ++it) {
            it->back() += prev(it)->back();
        }
        for(auto it = next(grid.back().rbegin()); it < grid.back().rend(); ++it) {
            *it += *(prev(it));
        }
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]); 
            }
        }
        return grid[0][0];
    }
};
