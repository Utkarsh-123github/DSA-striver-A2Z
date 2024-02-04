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
        next = NULL;
    }
};

Node* convertArr2LL(vector<int>&arr)
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

// Brute Approach :- Using extra space of vector of size n1+n2
// SC = O(n1+n2)
// TC = O(n1+n2)

Node* mergeList(Node* head1 , Node* head2)
{
    vector<int>ans;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL)
    {
      if(temp1->data <=temp2->data)
      {
        ans.push_back(temp1->data);
        temp1 = temp1->next;
      }
      else
      {
        ans.push_back(temp2->data);
        temp2 = temp2->next;
      }
    }
    while(temp1!=NULL)
    {
      ans.push_back(temp1->data);
      temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
      ans.push_back(temp2->data);
      temp2 = temp2->next;
    }
    Node* ansList = convertArr2LL(ans);
    return ansList;
}

// Optimal Approach :- Using dummy Node
// TC = O(n1+n2)
// SC = O(1)

Node* mergeLL(Node* head1, Node* head2)
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