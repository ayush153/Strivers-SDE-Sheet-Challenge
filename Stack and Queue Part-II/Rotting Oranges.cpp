#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    vector<int> dir={-1,0,1,0,-1};
    queue<pair<int,int>> q;
    int fresh = 0;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if(grid[i][j] == 2)
          q.push({i,j});
        if(grid[i][j] == 1)
          fresh++;
      }
    }
    int ans = -1;
    while(!q.empty())
    {
      int sz = q.size();
      while(sz--)
      {
        pair<int,int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
          int a = p.first+dir[i];
          int b = p.second+dir[i+1];
          if(a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1)
          {
            grid[a][b] = 2;
            q.push({a,b});
            fresh--; 
          }
        }
      }
      ans++;
    }
    if(fresh > 0) return -1; 
    if(ans == -1) return 0; 
    return ans;
}
