class Solution {
private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {-1, 0, 1, 0};
    const int WATER = 0;
    const int LAND = 1;
    const int MARKED = 2;
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = MARKED;
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dy[i];
            int newCol = col + dx[i];
            if (newRow >= grid.size() || newRow < 0 || newCol >= grid[0].size() || newCol < 0)
                continue;
            if (grid[newRow][newCol] != LAND)
                continue;
            area += dfs(grid, newRow, newCol);
        }
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == LAND) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
};