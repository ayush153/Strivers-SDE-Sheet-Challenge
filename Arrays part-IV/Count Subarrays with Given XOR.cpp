#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int,int> mp;
    int n = arr.size();
    int temp = 0,cnt = 0;

    for(int i = 0; i < n; i++)
    {
        temp ^= arr[i];
        if(temp == x) cnt++;
        int y = temp ^ x;   
        cnt += mp[y];
        mp[temp]++;
    }
    return cnt;
}
