#include <bits/stdc++.h> 
void helper(int idx, int n, vector<int> v, vector<int>& arr, vector<vector<int>>& ans)
{
    ans.push_back(v);
    
    for(int i = idx; i < n; i++)
    {
        if(i != idx && arr[i] == arr[i-1])
            continue;
        v.push_back(arr[i]);
        helper(i+1, n, v, arr, ans);
        v.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> v;
    helper(0, n, v, arr, ans);
    return ans;
}
