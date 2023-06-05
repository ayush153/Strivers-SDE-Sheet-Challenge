#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long curr_sum = arr[0];
    long long max_sum = 0;
    for(int i = 1; i < n; i++)
    {
        curr_sum = max((long long) arr[i],curr_sum+arr[i]);
        max_sum = max(max_sum,curr_sum);
    }
    return max_sum;
}
