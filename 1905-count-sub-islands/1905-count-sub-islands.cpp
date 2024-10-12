class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        // Check bounds and if the cell is water or already visited
        if (row < 0 || row >= grid2.size() || col < 0 || col >= grid2[0].size() || grid2[row][col] == 0) {
            return true;
        }
        
        // Mark the current cell as visited in grid2
        grid2[row][col] = 0;
        
        // Check if this cell is a valid sub-island cell (should also be land in grid1)
        bool isSubIsland = grid1[row][col] == 1;
        
        // Continue DFS in all 4 directions (down, up, right, left)
        isSubIsland &= dfs(grid1, grid2, row + 1, col);
        isSubIsland &= dfs(grid1, grid2, row - 1, col);
        isSubIsland &= dfs(grid1, grid2, row, col + 1);
        isSubIsland &= dfs(grid1, grid2, row, col - 1);
        
        return isSubIsland;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        
        // Traverse the entire grid2
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                // If we find a land cell in grid2, initiate DFS
                if (grid2[i][j] == 1) {
                    // Perform DFS and check if this island is a sub-island
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};