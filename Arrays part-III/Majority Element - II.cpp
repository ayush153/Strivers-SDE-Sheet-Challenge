#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> v;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto i : mp)
    {
        if (i.second > n / 3)
            v.push_back(i.first);
    }
    return v;
}
