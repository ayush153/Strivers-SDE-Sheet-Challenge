#include <bits/stdc++.h> 
bool isPalindrome(string &str , int start, int end)
{
    while(start <= end)
    {
        if(str[start++] == str[end--])
            continue;
        else
            return false;
    }
    return true;
}
    
    void helper(int idx, string s, vector<string> ds, vector<vector<string>>& ans)
    {
        if(idx == s.size())
        {
            ans.push_back(ds);
            return ;
        }
        
        for(int i = idx; i < s.size(); i++)
        {
            if(isPalindrome(s, idx, i))
            {
                ds.push_back(s.substr(idx,i - idx + 1));
                helper(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> ds;
    vector<vector<string> > ans;
    helper(0,s, ds, ans);
    return ans;
}
    

