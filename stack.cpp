#include<iostream>



class Stack
{
    public:
    int *arr;
    int capacity;
    int TOP;

    Stack(int size)
    {
        capacity=size;
        arr=new int[capacity];
        TOP=-1;
    }
    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty(){return TOP==-1;}

    void push_back(int value)
    {
        if(TOP>capacity-1)
        {
            std::cout<<"STACK OVERFLOW\n";
            return;
        }
        else{
            TOP++;
            arr[TOP]=value;
        }
    }

    void pop_pack()
    {
        if(isEmpty())
        {
            std::cout<<"STACK UNDERFLOW\n";
            return;
        }
        else{
            TOP--;
        }
    }

    void size()
    {
        if(isEmpty())
        {
            std::cout<<"STACK is EMPTY\n";
            return;
        }
        else
        std::cout<<"Size is "<<capacity <<"\n";
    }

    void peek()
    {
        if(isEmpty())
        {
           std::cout<<"STACK is EMPTY\n"; 
           return;
        }
        else{
            std::cout<<arr[TOP];
        }
    }
};









int main()
{
Stack s(5);
s.push_back(2);
s.peek();
s.pop_pack();
s.peek();


return 0;
}