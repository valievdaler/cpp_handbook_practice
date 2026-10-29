#include<iostream>
struct Node
{
    Node*next;
    int val;

    Node(int val)
    {
        this->val=val;
        next=nullptr;

    }
};

class Stack
{
    private:
    Node* Top;
    public:
    Stack()
    {
        Top=nullptr;
    }

    bool isEmpty()
    {
        return Top==nullptr;
    }

    void push(int val)
    {
        
        
            Node* newNode=new Node(val);
            newNode->next=Top;
            Top=newNode;
            std::cout<<"New Element is added "<<val<<std::endl;
        
    }

    void pop()
    {
        if(isEmpty())
        {
            std::cout<<"Empty\n";
            return;
        }
        else{
            Node*temp=Top;
            Top=Top->next;
            std::cout<<"Deleted "<<temp->val<<std::endl;
            delete temp;
        }
    }

    void peek()
    {
        if(isEmpty())
        {
            std::cout<<"Empty\n";
            throw std::runtime_error("Stack is Empty");
        }
        else{
            std::cout<<"Top is "<<Top->val<<std::endl;
        }
    }

};

int main()
{

    Stack s;
    s.push(10);
    s.peek();
    s.push(20);
    s.peek();
    s.pop();


    return 0;
}