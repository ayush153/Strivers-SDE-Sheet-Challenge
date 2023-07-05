#include <bits/stdc++.h> 
bool canPlace(int dist, int c, vector<int> positions, int n){
	int ninjasplaced = 1;
    int recentplacedat = 0;
    for(int i = 1; i < n; i++)
	{
        if(positions[i] - positions[recentplacedat] >= dist)
		{
            ninjasplaced++;
            recentplacedat = i;
        }
    }
    if(ninjasplaced >= c)
        return true;
    else
        return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int low = 0;
	int high = positions[n-1] - positions[0];
	int ans = 0;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(canPlace(mid, c, positions, n))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return ans;
}
