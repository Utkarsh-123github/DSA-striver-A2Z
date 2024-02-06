#include<bits/stdc++.h>
using namespace std;

class Stack 
{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size1)
    {
        size = size1;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow "<<endl;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int peek()
    {
        if(top>=0 && top<size)
        {
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1)return true;
        else return false;
    }
};

int main()
{
    Stack st(5);
    st.push(11);
    st.push(22);
    st.push(33);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

}