int cutRod(vector<int> &cuts, int n)
{
	// Write your code here.
	int dp[n];
    dp[0] = cuts[0];
    for(int i = 1; i < n; i++)
    {
        int m = cuts[i];
        for(int j = i-1; j >= 0; j--)
            m = max(cuts[i-j-1] + dp[j],m);
        dp[i] = m;
    }
    return dp[n-1];
}

