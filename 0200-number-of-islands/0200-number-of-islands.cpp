class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') { return; }
        grid[row][col] = '0';
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // depth first search
        // island 1) has to hit matrix edge 2) has to hit the 0 (water)
        if (grid.empty()) { return 0; }
        
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};