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

void PrintLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Brute Approach
// TC = O(2n + nlogn)
//SC = O(n)

Node* sortLL(Node* head)
{
    vector<int>arr;
    Node* temp = head;
    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    temp = head;
    for(int i=0;i<arr.size();i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

// Optimal Approach using merge Sort
// TC = (n + n/2)*log(n) ~ n*log(n)
// SC = O(1)

Node* findMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
} 

Node* mergeLL(Node* head1, Node* head2)
{
    if(head1 == NULL)return head2;
	if(head2 == NULL)return head1;
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

Node* mergeSortLL(Node* head)
{
    if(head == NULL || head->next == NULL)return head;
    Node* mid = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = mid->next;
    mid->next = NULL;
    leftHead = mergeSortLL(leftHead);
    rightHead = mergeSortLL(rightHead);
    return mergeLL(leftHead,rightHead);
}

int main()
{
    vector<int>arr = {10,8,9,2,3,5,4};
    Node* head = convertArr2LL(arr);
    head = mergeSortLL(head);
    PrintLL(head);
}