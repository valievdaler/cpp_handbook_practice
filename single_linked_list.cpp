#include<iostream>

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};

class List
{
    private:
    Node* head;
    
    public:
    List()
    {
        head=nullptr;
    }
    ~List()
    {
        Node* cur=head;
        while(cur!=nullptr)
        {
            Node*newNode=cur->next;
            delete cur;
            cur=newNode;
        }
    }

    bool isEmpty()
    {
        return head==nullptr;
    }

    void push_front(int val)
    {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;   
    }

    void push_back(int val)
    {
        Node* newNode=new Node(val);
        if(head==nullptr)
        {
            head=newNode;
            return;
        }
        Node*cur=head;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=newNode;
    }

    void remove(int val)
    {
        if(head==nullptr)
        {
            return;
        }
        if(head->data==val)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }

        Node*cur=head;
        while(cur->next!=nullptr && cur->next->data!=val)
        {
            cur=cur->next;
        }
        if(cur->next!=nullptr)
        {
            Node*temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
        }
        

    }

    void print()
    {
        Node* cur=head;
        while(cur!=nullptr)
        {
            std::cout<<cur->data<<std::endl;
            cur=cur->next;
        }
    }
};


int main()
{
    List lst;
    lst.push_front(10);
    lst.push_back(30);
    lst.push_front(20);

    if(lst.isEmpty())
    {
        std::cout<<"the list is empty!"<<std::endl;
    }
    else
    {
        
        lst.print();
    }
    std::cout<<"\n";
    lst.remove(10);
    lst.print();
    
    return 0;
}