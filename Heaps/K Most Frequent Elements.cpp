#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr){
    // Write your code here.
    unordered_map<int,int> mp;
    for(auto num : arr)
        mp[num]++;
    
    priority_queue<pair<int,int>> pq;
    vector<int>ans;
    for(auto i = mp.begin(); i != mp.end(); i++)
    {
        pq.push(make_pair(i->second,i->first));
        if(pq.size() > mp.size() - k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
