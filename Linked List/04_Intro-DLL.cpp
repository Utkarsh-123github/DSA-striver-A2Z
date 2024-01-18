#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(int data1 , Node* next1, Node* previous1)
    {
        data = data1;
        next = next1;
        previous = previous1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        previous = nullptr;
    }
};

Node* convertArr2DLL(vector<int>arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->previous = prev;
        prev = temp;
    }
    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8};
    Node* head = convertArr2DLL(arr);
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<head->next->data;
    return 0;

}

