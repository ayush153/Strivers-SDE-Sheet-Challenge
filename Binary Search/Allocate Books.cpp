#include <bits/stdc++.h> 
bool isPossible(int n, int m, vector<int> temp,long long mid){
    int day = 1;
    long long time = 0;
    for(int i = 0; i < m; i++)
    {
        if(time + temp[i] <= mid)
           time += temp[i];
       	else
		{
            day++;
            if(day > n || temp[i] > mid)
               return false;
            time = temp[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long sum = 0;
	long long low = 0;
	long long ans = -1;
	for (int i = 0; i < m; i++)
		sum += time[i];
	long long high = sum;
	long long mid = low + (high - low) / 2;
	while(low <= high)
	{
		if(isPossible(n,m,time,mid))
		{
			high = mid - 1;
			ans = mid;
		}
		else
			low = mid + 1;
		
		mid = low + (high - low)/2;
	}
	return ans;

}
