class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int row, int col, int& area)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
        {
            return;
        }
        grid[row][col] = 0;
        area++;
        dfs(grid, row+1, col, area);
        dfs(grid, row-1, col, area);
        dfs(grid, row, col+1, area);
        dfs(grid, row, col-1, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int curArea;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    curArea = 0;
                    dfs(grid, i, j, curArea);
                    if (curArea > maxArea)
                    {
                        maxArea = curArea;
                    }
                }
            }
        }
        return maxArea;
    }
};