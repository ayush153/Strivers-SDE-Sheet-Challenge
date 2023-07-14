#include <bits/stdc++.h> 
int job(vector<vector<int>> &jobs, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int skip = job(jobs, i + 1, j, n, dp);
    int done = 0;
    if (jobs[i][0] - j > 0)
        done = jobs[i][1] + job(jobs, i + 1, j + 1, n, dp);
    return dp[i][j] = max(skip, done);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end());
    int n = jobs.size();
    vector<int> dp(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int skip = dp[j];
            int done = 0;
            if (jobs[i][0] - j > 0)
                done = jobs[i][1] + dp[j + 1];
            curr[j] = max(skip, done);
        }
        dp = curr;
    }
    return dp[0];
}

