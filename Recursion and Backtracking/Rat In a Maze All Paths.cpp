#include <bits/stdc++.h> 
void helper(int i, int j, int n, vector<vector<int>>& visited, vector<vector<int>>& maze, vector<vector<int>>& ans)
{
  if(i < 0 || j < 0 || i >= n || j >= n || !maze[i][j] || visited[i][j])
    return ;

  if(i == n-1 && j == n-1)
  {
    visited[i][j] = 1;
    vector<int> cur;
    for(auto it : visited)
    {
      for(auto x : it)
        cur.push_back(x);
    }

    ans.push_back(cur);
    visited[i][j] = 0;
    return;
  }

  visited[i][j] = 1;

  helper(i, j+1, n, visited, maze, ans);
  helper(i+1, j, n, visited, maze, ans);
  helper(i, j-1, n, visited, maze, ans);
  helper(i-1, j, n, visited, maze, ans);

  visited[i][j] = 0;

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  helper(0, 0, n, visited, maze, ans);

  return ans;
}
