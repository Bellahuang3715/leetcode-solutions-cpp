class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1) take the transpose
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i+1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // 2) reverse each row
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};