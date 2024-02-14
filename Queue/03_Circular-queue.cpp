#include<bits/stdc++.h>
using namespace std;

class circularQueue
{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    circularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int value){
        // Check array is full
        if((front == 0 && rear == size-1)||(front!=0 && front == (rear+1)%size))
        {
            return false;
        }
        // Check for empty array
        if(front == -1)
        {
            front = rear = 0;
            arr[front] = value;
        }
        else if(front!=0 && rear == size-1)
        {
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Check for empty array
        if(front==-1)
        {
            return -1;
        }
        // check for single element
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(front == size-1)
        {
            front = 0;
        }
        else{
            front++;
        }
        return ans;

    }
};