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
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void PrintLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deleteMiddle(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    if(head->next->next == NULL)
    {
        head->next = NULL;
        return head;
        
    }
    Node* slow = head;
    Node* prev = NULL;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

int main()
{
    vector<int>arr = {1,2,2,2,1,3};
    Node* head = convertArr2LL(arr);
    PrintLL(head);
    cout<<endl;
    Node* newLL = deleteMiddle(head);
    PrintLL(newLL);
    return 0;
}