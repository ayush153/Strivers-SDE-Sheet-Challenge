#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> ans;
    for(int i = 0; i < n; i++) 
    {
        auto lb = lower_bound(ans.begin(), ans.end(), arr[i]);
        if(lb == ans.end())
            ans.push_back(arr[i]);
        else 
            *lb = arr[i];
    }
    return ans.size();
}

