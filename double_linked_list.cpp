#include<iostream>

struct Node
{
    
    Node* next,*prev;
    int val;

    

    Node(int val)
    {
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }


};

class DoubleList
{

    private:
    Node* head;

    public:
    DoubleList()
    {
        head=nullptr;
    }
    ~DoubleList()
    {

    }

    bool isEmpty()
    {
        return head==nullptr;
    }

    void push_back(int val)
    {
        Node*newNode=new Node(val);
        if(head==nullptr)
        {
          head=newNode; 
          return; 
        }

        Node* cur=head;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }

        cur->next=newNode;
        newNode->prev=cur;
    }

    void insert(int index,int val)
    {
        
        if(index<0)return;
        Node* newNode=new Node(val);

        if(index==0)
        {
            if(head!=nullptr)
            {
                newNode->next=head;
                head->prev=newNode;
            }
            head=newNode;
            return;
        }

        Node* cur=head;
        for(int i=0;i<(index-1) && (cur!=nullptr); ++i)
        {
            cur=cur->next;
        }

        if(cur==nullptr)
        {
            delete newNode;
            return;
        }

        Node*nextNode=cur->next;

        if(nextNode!=nullptr)
        {
            nextNode->prev=newNode;
        }
        

        newNode->next=nextNode;
        newNode->prev=cur;
        cur->next=newNode;
    }

    void remove(int val)
    {
        Node*cur=head;
        while(cur!=nullptr && cur->val!=val)
        {
            cur=cur->next;
        }
        if(cur==nullptr)return;

        if(cur==head && head!=nullptr)
        {
            head=head->next;
            if(head!=nullptr){head->prev=nullptr;}

        }
        else
        {
            cur->prev->next=cur->next;
            if(cur->next!=nullptr)cur->next->prev=cur->prev;
        }

        delete cur;
    }

    void clear()
    {
        Node*cur=head;
        while(cur!=nullptr)
        {
            Node*nextNode=cur->next;
            delete cur;
            cur=nextNode;

        }
        head=nullptr;
    }

    void print()
    {
        Node*cur=head;
        while(cur!=nullptr)
        {
            std::cout<<cur->val<<" ";
            cur=cur->next;
        }
    }

    void print_backward()
    {
        Node*cur=head;
        if(head==nullptr)return;

        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }

        while(cur!=nullptr)
        {
            std::cout<<cur->val<<" ";
            cur=cur->prev;
        }
    }

    bool find(int val)
    {
        Node*cur=head;
        if(head==nullptr)return false;
        
        while(cur->next!=nullptr && cur ->next->val!=val)
        {
            cur=cur->next;
        }

        if(cur==nullptr)return false;
        else return true;
    }
};


int main()
{
    DoubleList lst;
    lst.push_back(10);
    lst.insert(1,13);
    if(lst.isEmpty())
    {
        std::cout<<"the list is empty!"<<std::endl;
    }
    else
    {
        lst.print();
    }
    std::cout<<std::endl;
    lst.remove(13);
    std::cout<<"Remove function is called!"<<std::endl;
    lst.print();
    std::cout<<std::endl;
    lst.clear();
    std::cout<<"Clear is called!"<<std::endl;
    lst.print();

    lst.push_back(1);
    lst.push_back(2);
    lst.print();
    std::cout<<"Print is called!\n";
    
    lst.push_back(3);

    lst.push_back(4);
    
    lst.print_backward();
    std::cout<<"Print backward is called!\n";

    std::cout<<lst.find(2);


    return 0;
}