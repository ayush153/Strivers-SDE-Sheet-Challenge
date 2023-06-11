#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	sort(arr.begin(), arr.end()) ;
	int ans = 1,ans1;
	for(int i = 0; i < n; ++i)
	{
		if(ans == arr[i]) ans++;
			
		else if(arr[i] == ans-1) continue;
			
		else if(ans != arr[i]) break;
	}

	unordered_map<int,int> mp;
	for(auto it : arr)
		mp[it]++;

	for(auto it : mp)
	{
		if(it.second == 2)
		{
			ans1 = it.first;
			break;
		}
	}
	
	return {ans,ans1};
}

