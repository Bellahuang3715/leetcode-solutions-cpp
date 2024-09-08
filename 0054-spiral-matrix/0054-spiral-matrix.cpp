class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int m = matrix[0].size();
        int n = matrix.size();
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for (int j = top; j <= bottom; j++)
            {
                result.push_back(matrix[j][right]);
            }
            right--;
            
            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                {
                    result.push_back(matrix[bottom][j]);
                }
                --bottom;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                {
                    result.push_back(matrix[i][left]);
                }
                ++left;
            }
            
        }
        return result;
    }
};