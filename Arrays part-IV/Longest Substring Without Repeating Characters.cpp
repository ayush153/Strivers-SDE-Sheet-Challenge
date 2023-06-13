#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int ans = 0;
    vector<int> count(128);
    int i = 0;
    for (int j = 0; j < input.length(); j++)
    {
        count[input[j]]++;
        while (count[input[j]] > 1)
            count[input[i++]]--;
        ans = max(ans, j - i + 1);
    }
    return ans;
}
