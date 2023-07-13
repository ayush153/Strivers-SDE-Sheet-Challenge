#include <bits/stdc++.h>
void dfs(vector<int> adj[], int node, vector<int> &ans, vector<int> &vis)
{
    ans.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(adj, it, ans, vis);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    vector<int> vis(V, 0);
    vector<vector<int>> ans;
    for (int i = 0; i < E; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> res;
            dfs(adj, i, res, vis);
            ans.push_back(res);
        }
    }
    return ans;
}
