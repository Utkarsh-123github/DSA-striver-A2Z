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
};

Node* convertArr2LL(vector<int>arr)
{
    Node* head = new Node(arr[0],nullptr);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i],nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int countElements(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* deleteHeadElement(Node* head)
{
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTailElement(Node* head)
{
    Node* temp = head;
    if(head == nullptr || head->next == nullptr )return nullptr;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteKthElement(Node* head , int k)
{
    // Check if the list is empty
    if (head == NULL)
        return head;

    // If k is 1, delete the first node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    // Traverse the list to find the k-th node
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        // If the k-th node is found
        if (cnt == k) {
            // Adjust the pointers to skip the k-th node
            prev->next = prev->next->next;
            // Delete the k-th node
            delete temp;
            break;
        }
        // Move to the next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = deleteKthElement(head,1);
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;

}