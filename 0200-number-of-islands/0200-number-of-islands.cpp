class Solution {
public:
    // depth first search
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') { return; }
        grid[row][col] = '0';
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
    
    // breath first search
    void bfs(vector<vector<char>>& grid, int row, int col)
    {
        // positions to visit
        queue<pair<int, int>> q;
        q.push({row, col});
        
        // arrays to help traverse the 4 directions (up, down, left, right)
        vector<int> directionX = {1, -1, 0, 0};  // down, up, right, left
        vector<int> directionY = {0, 0, 1, -1};  // down, up, right, left
        
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++)
            {
                int newX = x + directionX[i];
                int newY = y + directionY[i];
                
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size())
                {
                    if (grid[newX][newY] == '1')
                    {
                        grid[newX][newY] = '0';
                        q.push({newX, newY});
                    }
                }
            }
        }
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
                    bfs(grid, i, j);
                    // dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};