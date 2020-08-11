/*
    https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        if(height == 0 || width == 0)
            return 0;
        for(int i = width - 2; i >= 0; i--) 
            grid[height - 1][i] += grid[height - 1][i + 1];

        for(int i = height - 2; i >= 0; i--)
            grid[i][width - 1] += grid[i + 1][width - 1];
        
        for(int i = height - 2; i >= 0; i--) {
            for(int j = width - 2; j >= 0; j--)
                grid[i][j] += max(grid[i + 1][j], grid[i][j + 1]);
        }
        return grid[0][0];
    }
};