#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    string data;
    Node* next;
    Node* back;
    Node(): data(0),next(nullptr),back(nullptr){}
    Node(string data):data(data),next(nullptr),back(nullptr){}
    Node(string data,Node* next,Node* back):data(data),next(next),back(back){}
};

class Browser
{
    Node* currentPage;
    public:
    
    Browser(string &homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
        // Write you code here
        Node* newPage = new Node(url);
        currentPage->next = newPage;
        newPage->back = currentPage;
        currentPage = newPage;
    }

    string back(int steps)
    {
        while(steps)
        {
            if(currentPage->back)
            {
                currentPage = currentPage->back;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while(steps)
        {
            if(currentPage->next)
            {
                currentPage = currentPage->next;
            }
            else break;
            steps--;
        }
        return currentPage->data;
    }
};
