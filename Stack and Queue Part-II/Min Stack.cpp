#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	int cnt;
    int *miny;
    int *arr;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            cnt = -1;
            arr = new int[100000];
            miny = new int[100000];
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			cnt++;
            arr[cnt] = num;
            if(cnt == 0)
                miny[cnt] = num;
            else
                miny[cnt]=min(miny[cnt-1],num);   
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(cnt == -1)
                return -1;
            else
                return arr[cnt--];
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(cnt == -1)
                return -1;
            else
                return arr[cnt];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(cnt == -1)
                return -1;
            else
                return miny[cnt];
		}
};
