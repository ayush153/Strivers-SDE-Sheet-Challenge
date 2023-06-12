#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	if (n == 0)
        return 1;
    
    long long ans = 1;
	long long temp = m;
    x = x % temp;
    
    while (n > 0) {
        if (n & 1)
            ans = (((ans%temp)*x)%temp)%temp;
        
        x = (((x%temp)*x)%temp)%temp;
        n = n >> 1;
    }
    
    return ans%temp;
}
