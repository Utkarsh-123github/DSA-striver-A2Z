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

Node* reverse(Node* head)
{
    if(head == NULL || head->next== NULL)return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// TC = O(3n) SC = O(1)

Node* addOne(Node* head)
{
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp!=NULL)
    {
        temp->data = temp->data + carry;
        if(temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1)
    {
        Node* newLink = new Node(carry);
        head = reverse(head);
        newLink->next = head;
        return newLink;
    }
    head = reverse(head);
    return head;
}

// Recursive approach
// SC = O(n) TC = O(n)

int helper(Node* temp)
{
    if(temp == NULL)return 1;
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10)return 0;
    temp->data = 0;
    return 1;
}

Node* RecursiveAddOne(Node* head)
{
    int carry = helper(head);
    if(carry == 1)
    {
        Node* newHead = new Node(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}
int main()
{
    vector<int>arr = {9,9,8};
    Node* head = convertArr2LL(arr);
    head = RecursiveAddOne(head);
    PrintLL(head);
    return 0;
}