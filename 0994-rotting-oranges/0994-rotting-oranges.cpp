class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        
        // no fresh oranges to rot
        if (fresh == 0)
        {
            return 0;
        }
        
        // directions array to move up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
            int size = q.size();
            bool rot = false;       // track if rot happens in current minute
            for (int i = 0; i < size; i++)
            {
                auto [x, y] = q.front();        // current rotting orange
                q.pop();
                
                // explore all 4 adjacent directions
                for (auto& dir : directions)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    // check bounds & if it is a fresh orange
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        // rot the fresh orange
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                        rot = true;
                    }
                }
            }
            if (rot) { minutes++; }
        }
        
        return fresh == 0 ? minutes : -1;
    }
};