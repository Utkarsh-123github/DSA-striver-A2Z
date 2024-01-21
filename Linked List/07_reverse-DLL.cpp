#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1 , Node* next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* convertArr2DLL(vector<int>arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Brute approach using stack

Node* reverseDLL(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

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
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Optimal Approach

Node* ReverseDLL(Node* head) {
    
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed
        // return the current head
        return head; 
    }
    
     // Initialize a pointer to
     // the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to
    // the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        prev = current->back; 
        
        // Swap the previous and
        // next pointers
        current->back = current->next; 
        
        // This step reverses the links
        current->next = prev;          
        
        // Move to the next node
        // in the original list
        current = current->back; 
    }
    
    // The final node in the original list
    // becomes the new head after reversal
    return prev->back;
}


int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8};
    Node* head = convertArr2DLL(arr);
    head = ReverseDLL(head);
    printDLL(head);
    return 0;
}

