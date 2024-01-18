#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(vector<int>arr)
{
    Node* head = new Node(arr[0],nullptr);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i],nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* insertAtHead(Node* head , int el)
{
    Node* newElement = new Node(el,nullptr);
    newElement->next = head;
    head = newElement;
    return head;
}

Node* insertAtTail(Node* head , int el)
{
    Node* newElement = new Node(el,nullptr);
    Node* temp = head;
    if(temp == nullptr)return newElement;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newElement;
    return head;
}

Node* insertAtKthPosition(Node* head , int el , int k)
{
    if(head == nullptr){
        if(k==1)return new Node(el,nullptr);
        else return nullptr;
    }
    if(k==1)
    {
        Node* newElement = new Node(el,nullptr);
        newElement->next = head;
        head = newElement;
        return head;
    }

    int count = 0;
    Node* temp = head;
    while(temp != nullptr)
    {
        count++;
        if(count == k-1)
        {
            Node* newElement = new Node(el,nullptr);
            newElement->next = temp->next;
            temp->next = newElement;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = insertAtKthPosition(head,10,5);
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;

}