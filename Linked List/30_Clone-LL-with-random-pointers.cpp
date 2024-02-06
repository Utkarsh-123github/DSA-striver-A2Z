#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
		int data;
		Node *next;
 		Node *random;
		Node() : data(0), next(nullptr), random(nullptr){};
		Node(int x) : data(x), next(nullptr), random(nullptr) {}
		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 };

// Brute Approach using hash map
// TC = O(2n + logn)
// SC = O(2n)

Node* cloneLL(Node* head)
{
    Node* temp = head;
    map<Node*,Node*>mpp;
    while(temp!=NULL)
	{
		Node* newNode = new Node(temp->data);
		mpp[temp] = newNode;
		temp = temp->next;
	}
	temp = head;
	while(temp!=NULL)
	{
		Node* copyNode = mpp[temp];
		copyNode->next = mpp[temp->next];
		copyNode->random = mpp[temp->random];
		temp = temp->next;
	}
	return mpp[head];
}

// Optimal Approach :-
// Insert copy Nodes in between the real nodes
// Connect random pointer
// Connect the next pointer

// TC = O(3n)
// SC = O(n) this cannot be omitted bcoz question demands this

// Step-1
void insertCopyinBetween(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        Node* nextElement = temp->next;
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = nextElement;
    }
}

// Step-2
void connectRandomPointers(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        Node* copy = temp->next;
        if(temp->random)
        {
            copy->random = temp->random->next;
        }
        else{
            copy->random = nullptr;
        }
        temp = temp->next->next;
    }
}

// Step-3
Node* getDeepCopyList(Node* head)
{
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* t1 = dummy;
    while(temp!=NULL)
    {
        t1->next = temp->next;
        t1 = t1->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummy->next;
}

// Final function

Node* CloneLL(Node* head)
{
    insertCopyinBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}