#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int Front;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        Front = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (Front == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear != size)
            arr[rear] = data;
            rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (Front == rear)
            return -1;
        else
        {
            int ans = arr[Front];
            arr[Front] = -1;
            Front++;
            if (Front == rear)
            {
                Front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if (rear == Front)
            return -1;
        else
            return arr[Front];
    }
};
