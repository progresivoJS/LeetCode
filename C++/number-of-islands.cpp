class Solution {
private:
    const char WATER = '0';
    const char LAND = '1';
    const char MARKED = '2';
    
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {-1 ,0, 1, 0};
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = MARKED;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dy[i];
            int newCol = col + dx[i];
            if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size())
                continue;
            if (grid[newRow][newCol] != LAND)
                continue;
            dfs(grid, newRow, newCol);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == LAND) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};