#include <bits/stdc++.h> 
void words(string &s, int start, vector<string> &dictionary, vector<string> &ans, string &curr) 
{
    if(start >= s.size()) 
    {
        ans.push_back(curr);
        return;
    }
    
    for(int i = start; i < s.size(); i++)
     {
        string temp = s.substr(start, i-start+1);
        bool res = false;
        for(string st : dictionary) 
        {
            if(st.compare(temp) == 0)
             {
                res = true;
                break;
            }
        }
        
        if(res)
        {
            string x = curr;
            curr += temp + " ";
            words(s, i+1, dictionary, ans, curr);
            curr = x;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string curr;
    words(s, 0, dictionary, ans, curr);
    return ans;

}
