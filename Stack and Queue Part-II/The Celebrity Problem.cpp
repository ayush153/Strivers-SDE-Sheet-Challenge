#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	int ans = 0;
    for(int i = 1; i < n; i++)
	{
        if(knows(ans,i) == 1)
            ans = i;
    }
    for(int i = 0; i < n; i++)
	{
        if(i != ans && (knows(ans,i) == 1 || knows(i,ans) == 0))
            return -1;
    }
   return ans;
}
