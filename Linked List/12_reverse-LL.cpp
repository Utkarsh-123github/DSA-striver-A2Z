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

// Brute approach using stack
// TC = O(2n) SC = O(n)

Node* reverseLL(Node* head)
{
    Node* temp = head;
    stack<int>st;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Optimal approach :- TC = O(n) SC = O(1)

Node* reverse(Node* head)
{
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=NULL)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Recursive approach
// TC = O(n) SC = O(n)

Node* recursiveReverse(Node* head)
{
    if(head == NULL || head->next == NULL)return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = recursiveReverse(head);
    PrintLL(head);
    return 0;
}