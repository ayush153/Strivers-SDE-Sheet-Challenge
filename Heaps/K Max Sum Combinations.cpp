#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	vector<int> ans;
	sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    priority_queue<pair<int, pair<int, int>>> pq; 
    set<pair<int, int>> vis; 
    
    pq.push({a[0]+b[0], {0 ,0}});
    vis.insert({0, 0});
    
    for(int i = 0; i < k; i++)
	{
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        if(p.second.first+1 < n && vis.find({p.second.first+1, p.second.second}) == vis.end()) 
		{
            vis.insert({p.second.first+1, p.second.second});
            int x = a[p.second.first+1] + b[p.second.second];
            pq.push({x, {p.second.first+1, p.second.second}});
        }
		
        if(p.second.second+1 < n && vis.find({p.second.first, p.second.second+1}) == vis.end()) 
		{
            vis.insert({p.second.first, p.second.second+1});
            int x = a[p.second.first] + b[p.second.second+1];
            pq.push({x, {p.second.first, p.second.second+1}});
        }
    }
    
    return ans;
}
