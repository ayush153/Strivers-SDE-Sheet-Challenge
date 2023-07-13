 bool dfs(int color, vector<int> graph[], vector<int>& colors) {
        for(auto it : graph[color])
		{
        	if(colors[it] == -1)
			{
            	colors[it] = 1-colors[color];
            	if(!dfs(it,graph,colors))
					return false;
        	}
			else if(colors[it] == colors[color])
				return false;
    	}
        return true;
    }
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
    vector<int> graph[n];
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < n; j++)
		{
            if(edges[i][j] == 1)
			{
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    vector<int>color(n,-1);
    for(int i = 0; i < n; i++)
	{
        if(color[i] == -1)
		{
            color[i] = 1;
            if(!dfs(i,graph,color))
				return false;
        }
    }
    return true;
}
