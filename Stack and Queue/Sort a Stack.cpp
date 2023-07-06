#include <bits/stdc++.h> 
void sorted(stack<int> &s, int num){
	if(s.empty() || (!s.empty() && s.top() < num)){
		s.push(num);
		return;
	}
	int n = s.top();
	s.pop();
	sorted(s,num);
	s.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
		return;
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	sorted(stack,num);
}
