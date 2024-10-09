class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) { return false; }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // start at top right corner of the matrix
        int row = 0;
        int col = cols - 1;
        
        while (row < rows && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            // matrix value is greater than target
            else if (matrix[row][col] > target)
            {
                col--;
            }
            // matrix value is smaller than target
            else
            {
                row++;
            }
        }
        return false;
    }
};