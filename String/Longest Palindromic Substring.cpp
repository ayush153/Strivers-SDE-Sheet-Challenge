string longestPalinSubstring(string str)
{
    // Write your code here.
    if(str.length() <= 1) return str;
        
    int max_len = 1;
    int n = str.length();
    int st = 0,end = 0;
    
    //For odd length
    for(int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while(l >= 0 && r < n)
        {
            if(str[l] == str[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        int len = r-l-1;
        if(len > max_len)
        {
            max_len=len;
            st = l+1;
            end = r-1;
        }
    }
    
    //For even length
    for(int i = 0; i < n; i++)
    {
        int l = i,r = i+1;
        while(l >= 0 && r < n)
        {
            if(str[l] == str[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        int len = r-l-1;
        if(len > max_len)
        {
            max_len = len;
            st = l+1;
            end = r-1;
        }
    }
    
    return str.substr(st,max_len);
}
