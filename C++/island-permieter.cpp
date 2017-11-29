class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    const int WATER = 0;
    const int LAND = 1;
    
    int calculatePerimeter(vector<vector<int>>& grid, int row, int col) {
        int perimeter = 4;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dy[i];
            int newCol = col + dx[i];
            if (newRow >= grid.size() || newRow < 0 || newCol >= grid[0].size() || newCol < 0)
                continue;
            if (grid[newRow][newCol] == LAND)
                perimeter--;
        }
        
        return perimeter;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == LAND)
                    perimeter += calculatePerimeter(grid, i, j);
            }
        }
        return perimeter;
    }
};