class Solution {
public:
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
                    dfs(board, i, j);
                }
            }
        }
        return battleships;
    }
};