class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.back().back() || obstacleGrid.front().front()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> grid(m, vector<long long>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    grid[i][j] = -1;
                }
            }
        }
        bool wasObstacle = false;
        for(auto it = grid.rbegin(); it != grid.rend(); ++it) {
            if(!wasObstacle && it->back() != -1) {
                it->back() = 1;
            }
            else {
                wasObstacle = true;
            }
        }
        wasObstacle = false;
        for(auto it = grid.back().rbegin(); it != grid.back().rend(); ++it) {
            if(!wasObstacle && *it != -1) {
                *it = 1;
            }
            else {
                wasObstacle = true;
            }
        }
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                if(grid[i][j] == -1) {
                    continue;
                }
                int sum = 0;
                if(grid[i+1][j] != -1) {
                    sum += grid[i+1][j];
                }
                if(grid[i][j+1] != -1) {
                    sum += grid[i][j+1];
                }
                grid[i][j] = sum; 
            }
        }
        return grid[0][0];
    }
};
