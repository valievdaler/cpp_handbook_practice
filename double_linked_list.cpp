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

    void print()
    {
        Node*cur=head;
        while(cur!=nullptr)
        {
            std::cout<<cur->val;
            cur=cur->next;
        }
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

    return 0;
}