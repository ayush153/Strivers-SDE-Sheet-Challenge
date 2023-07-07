#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> ans(n, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        v1[i] = i;
        v2[i] = n - i - 1;
    }

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i]) 
        {
            v2[st.top()] = i - st.top() - 1;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) 
        st.pop();

    for (int i = n - 1; i >= 0; i--) 
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            v1[st.top()] = st.top() - i - 1;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) 
    {
        int d = v2[i] + v1[i];
        ans[d] = max(ans[d], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) 
    {
        if (ans[i] < ans[i + 1]) 
            ans[i] = ans[i + 1];
    }

    return ans;

}
