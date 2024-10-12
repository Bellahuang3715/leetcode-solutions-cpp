class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, int& componentSize)
    {
        visited[node] = true;
        componentSize++;
        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adjList, visited, componentSize);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);   // adjacency list
        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        vector<int> componentSizes;
        
        // group connected components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int componentSize = 0;
                dfs(i, graph, visited, componentSize);
                componentSizes.push_back(componentSize);
            }
        }
        
        // total number of node pairs in a graph - n(n-1) / 2
        // (number of ways to choose 2 nodes from n nodes)
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long reachablePairs = 0;
        
        for (int size : componentSizes) {
            reachablePairs += (long long)size * (size - 1) / 2;
        }
        
        return totalPairs - reachablePairs;
    }
};