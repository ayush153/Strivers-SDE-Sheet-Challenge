#include<bits/stdc++.h>
long coin(int *denominations, int n, int value, vector<vector<long>> &dp)
{ 
   if(n == 0)
      return (value % denominations[0] == 0);
   if(dp[n][value] != -1)
      return dp[n][value]; 
   long nontake = coin(denominations, n-1, value, dp);
   long take = 0;
   if(denominations[n] <= value)
      take = coin(denominations, n, value-denominations[n], dp);
   return dp[n][value] = nontake + take; 
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long> (value+1, -1));  
    return coin(denominations, n-1, value, dp);
}
