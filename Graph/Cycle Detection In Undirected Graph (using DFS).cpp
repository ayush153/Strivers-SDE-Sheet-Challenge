#include<bits/stdc++.h>
bool isCycleDFS(vector<int> adj[], int i, vector<bool> vis, int parent)
{
    vis[i] = true;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            if (isCycleDFS(adj, it, vis, i))
                return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycleDFS(adj, i, vis, -1))
                return "Yes";
        }
    }
    return "No";
}

