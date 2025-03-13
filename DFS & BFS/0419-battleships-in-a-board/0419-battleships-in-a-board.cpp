class Solution {
public:
    void bfs(vector<vector<char>>& board, int row, int col)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            vector<int> dirX = {1, -1, 0, 0};
            vector<int> dirY = {0, 0, 1, -1};
            
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                
                if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] != '.')
                {
                    if (board[newX][newY] == 'X')
                    {
                        board[newX][newY] = '.';
                        q.push({newX, newY});
                    }
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int row, int col)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '.')
        {
            return;
        }
        board[row][col] = '.';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        // depth first search
        int battleships = 0;
        if (board.empty()) { return 0; }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    battleships++;
                    // dfs(board, i, j);
                    bfs(board, i, j);
                }
            }
        }
        return battleships;
    }
};