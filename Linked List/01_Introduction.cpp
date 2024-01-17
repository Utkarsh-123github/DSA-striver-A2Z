#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1)
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

int search(Node* head , int value)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->data == value) return 1;
        temp = temp->next;
    }
    return 0;
}

int lengthOfLL(Node* head)
{
    Node* temp = head;
    int count = 0;
    while(temp!= nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int main()
{
    vector<int>arr = {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
    cout<<"Length of the Linked list is "<<lengthOfLL(head)<<endl;
    cout<<"Is the element 10 present in the LL :- "<<search(head,10)<<endl;
    return 0;

}
