#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q;
    int size;
    
   public:
    Stack() {
        // Implement the Constructor.
        size = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        size++;
        q.push(element);
        for(int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(!q.empty())
        {
            int a = q.front();
            q.pop();
            size--;
            return a;
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q.empty())
            return q.front();
        return -1;
    }
};
