#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N,vector<int>(N,INT_MAX));
    for(int i = 0; i < N; i++)
        dp[i][i] = 0;
    
    for(int i = N-1; i >= 1; i--)
    {
        for(int j = i+1; j < N; j++)
        {
            for(int k = i; k < j; k++)
            {
                int ans = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                dp[i][j] = min(ans,dp[i][j]);
            }
        }
    }
    return dp[1][N-1];
}
