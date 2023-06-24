#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<pair<int, pair<int,int>>> v;
    for(int i = 0; i < n; i++)
        v.push_back({end[i],{i+1, start[i]}});
    sort(v.begin(), v.end());
    int prev = -1;
    vector<int> ans;
    for(auto it : v)
    {
        int start = it.second.second, finish = it.first, idx = it.second.first;
        if(start > prev)
        {
            ans.push_back(idx);
            prev = finish;
        }
    }

    return ans;
}
