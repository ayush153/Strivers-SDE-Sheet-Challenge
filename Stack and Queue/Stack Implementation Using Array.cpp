#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int Top;
    int size;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->size = capacity;
        arr = new int[size];
        Top = -1;
    }

    void push(int num) {
        // Write your code here.
        if (size - Top!= 1)
        {
            Top++;
            arr[Top] = num;
        }
    }

    int pop() {
        // Write your code here.
        if (Top != -1)
        {
            int x = arr[Top];
            Top--;
            return x;
        }
        else
            return -1;
    }
    
    int top() {
        // Write your code here.
        if (Top != -1)
        {
            int x = arr[Top];
            return x;
        }
        else
            return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if (Top == -1)
            return 1;
        else
            return 0;
    }
    
    int isFull() {
        // Write your code here.
        if (size - Top == 1)
            return 1;
        else
            return 0;
    }
    
};
