#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();

    vector<pair<int,int>> activity;

    for(int i = 0; i < n; i++)
      activity.push_back({start[i], finish[i]});

    sort(activity.begin(), activity.end(), [&] (pair<int,int>&a, pair<int,int>&b)
    {
        return a.second < b.second;
    });

    int cnt = 0, end = -1;

    for(int i = 0; i < n; i++)
    {
       if(activity[i].first >= end)
       {
           cnt++;
           end = activity[i].second;
       }
    }

    return cnt;
}
