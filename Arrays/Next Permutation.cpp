#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i = n - 2;
    while (i >= 0 && permutation[i] >= permutation[i+1]) 
    {
        i--;
    }
    
    if (i >= 0)
    {
        int j = n - 1;
        while (j > i && permutation[j] <= permutation[i]) 
        {
            j--;
        }
        swap(permutation[i], permutation[j]);
    }
    int left = i + 1;
    int right = n - 1;
    while (left < right)
    {
        swap(permutation[left], permutation[right]);
        left++;
        right--;
    }
    
    return permutation;
}
