#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    if (n == 0)
        return;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    cout << arr[0] << " ";
    maxHeap.push(arr[0]);
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= maxHeap.top()) 
            maxHeap.push(arr[i]);
        else 
            minHeap.push(arr[i]);
        
        if (maxHeap.size() > minHeap.size() + 1) 
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if (maxHeap.size() == minHeap.size()) 
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        else 
            cout << maxHeap.top() << " ";
    }
}
