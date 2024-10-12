class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int row, int col, int& fish)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
        {
            return;
        }
        fish += grid[row][col];
        grid[row][col] = 0;

        dfs(grid, row+1, col, fish);
        dfs(grid, row-1, col, fish);
        dfs(grid, row, col+1, fish);
        dfs(grid, row, col-1, fish);
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        int fish;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] > 0)
                {
                    fish = 0;
                    dfs(grid, i, j, fish);
                    if (fish > maxFish)
                    {
                        maxFish = fish;
                    }
                }
            }
        }
        return maxFish;
    }
};