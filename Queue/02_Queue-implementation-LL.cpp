#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

class Queue
{
    Node* Front;
    Node* rear;
    public:
    Queue()
    {
        Front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        if(Front == NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int value)
    {
        Node* temp = new Node(value);
        if(rear == NULL)
        {
            rear = temp;
            Front = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue()
    {
        if(Front == NULL)
        {
            return -1;
        }
        else{
            int ans = Front->data;
            Node* temp = Front;
            Front = Front->next;
            if(Front == NULL)
            {
                rear = NULL;
            }
            free(temp);
            return ans;
        }
    }

    int front()
    {
        if(Front == NULL)
        {
            return -1;
        }
        else{
            return Front->data;
        }
    }
};