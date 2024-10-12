class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        visited[city] = true;
        for (int otherCity = 0; otherCity < isConnected.size(); ++otherCity)
        {
            if (isConnected[city][otherCity] == 1 && !visited[otherCity])
            {
                dfs(otherCity, isConnected, visited);  // Recursively visit connected cities
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;
        
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};