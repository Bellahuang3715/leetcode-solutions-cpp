class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int origColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) { return; }
        if (image[sr][sc] != origColor) { return; }
        image[sr][sc] = newColor;
        dfs(image, sr+1, sc, newColor, origColor);
        dfs(image, sr, sc+1, newColor, origColor);
        dfs(image, sr-1, sc, newColor, origColor);
        dfs(image, sr, sc-1, newColor, origColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if (original != color)
        {
            dfs(image, sr, sc, color, original);
        }
        return image;
    }
};