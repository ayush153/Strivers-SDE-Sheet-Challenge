#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int, int> mp;
  int n = arr.size();
  int sum = 0; 
  int ans = 0; 

  for (int i = 0; i < n; i++)
  {
      sum += arr[i];
      if(arr[i] == 0 && ans == 0)
          ans = 1;
      if(sum == 0)
          ans = i + 1;
      if (mp.find(sum) != mp.end())
          ans = max(ans, i - mp[sum]);
      else
          mp[sum] = i;
  }
  return ans;

}
