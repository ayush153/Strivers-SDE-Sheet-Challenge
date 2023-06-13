#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> st(arr.begin(),arr.end());
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!st.count(arr[i] - 1))
        {
            int curr = 1;
            int var = arr[i];
            while(st.count(var+1))
            {
                var++;
                curr++;
            }
            ans = max(ans,curr);
        }
    }  
    return ans;
}
