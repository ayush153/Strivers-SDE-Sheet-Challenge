#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    st.push(-1);
    vector <int> ans(n);
    for(int i = n-1; i >= 0; i--)
    {
        int val = arr[i];
        while(st.top() >= val)
            st.pop();
        ans[i] = st.top();
        st.push(val);
    }
    return ans;
}
