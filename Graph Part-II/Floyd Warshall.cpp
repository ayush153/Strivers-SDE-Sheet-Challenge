int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1e9));
    for (auto it : edges)
        adj[it[0]][it[1]] = it[2];

    int i = 1;
    while (i <= n)
    {
        adj[i][i] = 0;
        i++;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] == 1e9 || adj[k][j] == 1e9)
                    continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    return adj[src][dest];
}
