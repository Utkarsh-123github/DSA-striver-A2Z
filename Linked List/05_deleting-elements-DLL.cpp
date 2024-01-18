#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }   
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

Node* deleteHead(Node* head)
{
    if(head == nullptr || head->next == nullptr)return nullptr;
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;

}

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
     // If the list is empty or has only one node, return null
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
     // Traverse to the last node (tail)
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    
    // Free memory of the deleted node
    delete tail;  
    
    return head;
}

Node* deleteKthElement(Node* head , int k)
{
   if(head == nullptr)return nullptr;
   Node* kNode = head;
   int count = 0;
   while(kNode != nullptr)
   {
    count++;
    if(count==k)break;
    kNode = kNode->next;
   }
   Node* prev = kNode->back;
   Node* front = kNode->next;
   if(prev == nullptr && front == nullptr){
    delete kNode;
    return nullptr;
   }
   else if(prev == nullptr)
   {
    return deleteHead(head);
   }
   else if(front == nullptr)
   {
    return deleteTail(head);
   }

   prev->next = front;
   front->back = prev;
   kNode->next = nullptr;
   kNode->back = nullptr;
   delete kNode;
   return head;

}

int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8};
    Node* head = convertArr2DLL(arr);
    head = deleteKthElement(head , 1);
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;

}