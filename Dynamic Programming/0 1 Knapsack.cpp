#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<int>prev(w+1,0);
	vector<int>curr(w+1,0);
	for(int i = weights[0]; i <= w; i++)
		prev[i] = values[0];
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= w; j++)
		{
			int pick = INT_MIN;
			int not_pick = 0 + prev[j];
			if(weights[i] <= j)
				pick = values[i] + prev[j - weights[i]];
			curr[j] = max(pick,not_pick);
		}
		prev = curr;
	}
	return prev[w];
}
