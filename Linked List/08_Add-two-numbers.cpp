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

Node* addTwoNumbers(Node* num1, Node* num2)
{
    Node* t1 = num1;
    Node* t2 = num2;
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry=0;
    while(t1!=NULL || t2!=NULL)
    {
        int sum = carry;
        if(t1)
        {
            sum = sum + t1->data;
        }
        if(t2)
        {
            sum = sum + t2->data;
        }
        Node * newNode = new Node(sum%10);
        carry = sum/10;
        current->next = newNode;
        current = current->next;
        if(t1)
        {
            t1 = t1->next;
        }
        if(t2)
        {
            t2 = t2->next;
        }
    }
    if(carry)
    {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    return dummyNode->next;
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

int main()
{
    vector<int>arr1 = {1,2,3,4};
    vector<int>arr2 = {6,7,8,9};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node* ansLL = addTwoNumbers(head1,head2);
    PrintLL(ansLL);
    return 0;
}
