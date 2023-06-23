int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+n);
    sort(dt, dt+n);
    
    int platform = 0;
    int ans = 1;
    
    int i = 0, j = 0;
    while(i < n && j < n)
    {
        if(dt[j] >= at[i])
        {
            platform++;
            i++;
        }
        else if(at[i] > dt[j])
        {
            platform--;
            j++;
        }
        ans = max(ans, platform);
    }
    return ans;
}s
