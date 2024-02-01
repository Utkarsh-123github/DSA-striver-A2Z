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

Node* reverseLL(Node* head)
{
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* getKthNode(Node* head, int k)
{
    Node* temp = head;
    k = k-1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head,int k)
{
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp!=NULL)
    {
        Node* KthNode = getKthNode(temp,k);
        if(KthNode == NULL)
        {
            if(prevLast)
            {
                prevLast->next = temp;
            }
            break;
        }
        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        reverseLL(temp);
        if(temp == head)
        {
            head = KthNode;
        }
        else{
            prevLast->next = KthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;

}

int main() {
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    PrintLL(head);
    cout<<endl;
    // Reverse the linked list
    head = kReverse(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    PrintLL(head);

    return 0;
}