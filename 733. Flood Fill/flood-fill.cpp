class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    void dfs(vector<vector<int>>& image, int row, int col, int originColor, int newColor) {
        if (image[row][col] != originColor) return;
        image[row][col] = newColor;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dy[i];
            int newCol = col + dx[i];
            if (newRow >= image.size() || newRow < 0 || newCol >= image[0].size() || newCol < 0) continue;
            dfs(image, newRow, newCol, originColor, newColor);
        }
    }
public:    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};