#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    
    int maxProfit = 0, maxDeadline = 0;

    sort(jobs.begin(), jobs.end(), [&](const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    });

    for(auto it : jobs)
        maxDeadline = max(maxDeadline, it[0]);
    
    vector<bool> slots(maxDeadline + 1, false);

    for(int i = 0; i < n; i++)
    {
        for(int j = jobs[i][0]; j > 0; j--)
        {
            if(!slots[j])
            {
                slots[j] = true;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }

    return maxProfit;
}

