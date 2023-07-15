#include<bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	sort(arr.begin(),arr.end());
    vector<int> ans;
    
    for(int i = 0; i < queries.size(); i++)
	{
		int x = queries[i][0];
		int limit = queries[i][1];
		int maxy =-1;
		for(int j = 0; j < arr.size(); j++)
		{
			if(arr[j] > limit)
				break;
			else
			{
				int res = x^arr[j];
				maxy = max(maxy,res);
			}
			
		}
		ans.push_back(maxy);
 	}
	return ans;
}
