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
    if(head->next == NULL || head == NULL)return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// brute approach :- Using stack
// TC = O(2n) SC = O(n)
bool Palindrome(Node* head)
{
    stack<int>st;
    Node* temp = head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data != st.top())return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

// Optimal Approach :-  TC = O(2n) SC = O(1)
// Using tortoise and hare approach(fast and slow pointer approach)
bool palindrome(Node* head)
{
    if(head == NULL || head->next == NULL)return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* newHead = reverse(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL)
    {
        if(first->data != second->data)
        {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}

int main()
{
    vector<int>arr = {1,2,2,2,1};
    Node* head = convertArr2LL(arr);
    PrintLL(head);
    cout<<endl;
    cout<<palindrome(head);
    return 0;
}