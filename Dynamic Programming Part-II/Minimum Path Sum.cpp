#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            else if (i > 0)
                grid[i][0] += grid[i - 1][0];
            else if (j > 0)
                grid[0][j] += grid[0][j - 1];
        }
    }
    return grid[m - 1][n - 1];
}
