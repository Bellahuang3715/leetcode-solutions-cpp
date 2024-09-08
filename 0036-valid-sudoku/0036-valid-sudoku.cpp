class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // need to check 1) rows 2) columns 3) 3x3 boxes
        // create sets to track
        unordered_set<char> rows[9], cols[9], boxes[9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num = board[i][j];
                // skip is position is empty
                if (num == '.')
                    continue;
                
                if (rows[i].count(num))
                    return false;
                rows[i].insert(num);
                
                if (cols[j].count(num))
                    return false;
                cols[j].insert(num);
                
                int boxNum = (i/3) * 3 + (j/3);
                if (boxes[boxNum].count(num))
                    return false;
                boxes[boxNum].insert(num);
            }
        }
        return true;
    }
};