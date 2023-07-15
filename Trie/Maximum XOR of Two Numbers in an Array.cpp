#include <bits/stdc++.h> 
int maximumXor(vector<int> A)
{
    // Write your code here.   
    int ans = 0, prefix = 0;
    for (int i = 31; i >= 0; i--)
    {
        prefix = prefix | (1 << i);
        unordered_set<int> s;
        for (int n : A)
            s.insert(n & prefix);
        int c = ans | (1 << i);
        for (int a : s)
        {
            int b = c ^ a;
            if (s.find(b) != s.end())
            {
                ans = c;
                break;
            }
        }
    }
    return ans; 
}
