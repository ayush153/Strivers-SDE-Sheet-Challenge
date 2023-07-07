#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    stack<pair<int,int>> st;
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        if(st.empty())
            ans[i] = 1;
        else if(st.size() > 0 && st.top().first > price[i])
            ans[i] = 1;
        else if(st.size() > 0 && st.top().first <= price[i])
        {
            while(st.size() > 0 && st.top().first <= price[i])
                st.pop();
            if(st.empty())
                ans[i] = i+1;
            else
                ans[i] = i - st.top().second;
        }
        st.push({price[i],i});
    }
    return ans;
}
