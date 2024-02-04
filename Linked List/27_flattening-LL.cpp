#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
	int data;
	Node *next;
		Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* convertArr2LL(vector<int>&arr)
{
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++)
  {
    Node* temp = new Node(arr[i]);
    mover->child = temp;
    mover = temp;
  }
  return head;
}

// Brute approach :- using extra vector
// TC ~ O(2*(n*m)) + xlogx (xlogx for sorting)
// SC = O(n+m)

Node* flatten(Node* head)
{
    vector<int>arr;
    Node* temp = head;
    while(temp!=NULL)
    {
        Node* t2 = temp;
        while(t2!=NULL)
        {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    Node* ans = convertArr2LL(arr);
    return ans;
}

// Optimal Approach using merge LL concept

Node* mergeLL(Node* head1, Node* head2)
{
    Node* dummy = new Node(-1,NULL,NULL);
    Node* temp = dummy;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data<=t2->data)
        {
            temp->child = t1;
            temp = t1;
            t1 = t1->child;
        }
        else{
            temp->child = t2;
            temp = t2;
            t2 = t2->child;
        }
    }
    while(t1!=NULL)
    {
        temp->child = t1;
        temp = t1;
        t1 = t1->child;
    }
    while(t2!=NULL)
    {
        temp->child = t2;
        temp = t2;
        t2 = t2->child;
    }
    return dummy->child;
}

Node* Flatten(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* mergedHead = Flatten(head->next);
    return mergeLL(head,mergedHead);
}