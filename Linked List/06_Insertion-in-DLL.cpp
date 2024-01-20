#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1 , Node* next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    
    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
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
        temp->back = prev;
        prev = temp;
    }
    return head;
}

Node* insertAtHead(Node* head , int el)
{
    Node* newElement = new Node(el);
    head->back = newElement;
    newElement->next = head;
    newElement->back = nullptr;
    return newElement;
}

Node* insertAtTail(Node* head , int el)
{
    if(head == nullptr)return new Node(el);
    if(head->next == nullptr)
    {
        Node* newElement = new Node(el);
        head->next = newElement;
        newElement->back = head;
        return head;
    }
    Node* tail = head;
    while(tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node* Element = new Node(el);
    tail->next = Element;
    Element->back = tail;
    return head;
}

Node* insertBeforeKth(Node* head, int k, int el)
{
    if(k==1)return insertAtHead(head,el);
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr)
    {
        count++;
        if(count==k)
        {
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* element = new Node(el,temp,prev);
    prev->next = element;
    temp->back = element;
    return head;

}

int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8};
    Node* head = convertArr2DLL(arr);
    head = insertBeforeKth(head , 5,10);
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;

}
