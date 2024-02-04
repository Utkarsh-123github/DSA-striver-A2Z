#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
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

// Brute Approach
// TC = O(2*n*k) + O(n*klog(n*k)) 
// SC = O(2*n*k)
Node* mergeKLists(vector<Node*> &listArray){
    vector<int>arr;
    for(int i=0;i<listArray.size();i++)
    {
        Node* temp = listArray[i];
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* head = convertArr2LL(arr);
    return head;
}

// Better Approach
// TC ~O((n^3)
// SC = O(1)

Node* mergeLL(Node* head1 , Node* head2)
{
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data <= t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    while(t1!=NULL)
    {
        temp->next = t1;
        temp = t1;
        t1 = t1->next;
    }
    while(t2!=NULL)
    {
        temp->next = t2;
        temp = t2;
        t2 = t2->next;
    }
    return dummy->next;
}
Node* mergeKLists(vector<Node*> &listArray){
    Node* head = listArray[0];
    for(int i=1;i<listArray.size();i++)
    {
        head = mergeLL(head,listArray[i]);
    }
    return head;
}

// Optimal Approach - Using Priority Queue (PENDING)