class Solution {
public:
    
    void dfs(vector<vector<int>>& land, int row, int col, vector<int>& group)
    {
        if (row < 0 || row >= land.size() || col < 0 || col >= land[0].size() || land[row][col] == 0)
        {
            return;
        }
        land[row][col] = 0;
        if (row > group[2] || col > group[3])
        {
            group[2] = row;
            group[3] = col;
        }
        dfs(land, row+1, col, group);
        dfs(land, row-1, col, group);
        dfs(land, row, col+1, group);
        dfs(land, row, col-1, group);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> groups;
        
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (land[i][j] == 1)
                {
                    vector<int> group = {i, j, i, j};
                    dfs(land, i, j, group);
                    groups.push_back(group);
                }
            }
        }
        
        return groups;
    }
};