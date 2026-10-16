#include<iostream>

struct Node
{
    Node* next;
    int val;

    Node(int val)
    {
        this->val=val;
        next=nullptr;
    }
};

class Clist
{
private:
Node *head;

public:
Clist()
{
    head=nullptr;
}
~Clist()
{
    Clear();
}


void append(int val)
{
    Node* newNode=new Node(val);

    if(head==nullptr)
    {
        head=newNode;
        head->next=head;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
     temp->next=newNode;
     newNode->next=head;
}

void display()
{

    if(head==nullptr)
    {
        std::cout<<"List is Empty\n";
        return;
    }
    Node*temp=head;
    
    do{
        std::cout<<temp->val<<std::endl;
        temp=temp->next;
    }while(temp!=head);
}

void prepend(int val)
{
    Node*newNode=new Node(val);

    if(head==nullptr)
    {
        head=newNode;
        newNode->next=head;
        return;
    }


    Node*temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    newNode->next=head;
    temp->next=newNode;
    head=newNode;
}

void remove(int val)
{
    Node* temp=head;
    if(head->val==val)
    {
        if(head->next==head)
        {
            delete head;
            head=nullptr;
            return;
        }
        Node*last=head;
        while(last->next!=head )
        {
            last=last->next;
        }
        
        Node*temp=head;
        head=head->next;
        last->next=head;
        delete temp;
        return;
    }
    Node*prev=head;
    Node*cur=head->next;
    do
    {
        if(cur->val==val)
        {
            prev->next=cur->next;
            delete cur;
            return;
        }
        prev=cur;
        cur=cur->next;
    }while(cur!=head);


}

bool search(int val)
{
    if(head==nullptr)
    {
        std::cout<<"The list is empty!\n";
        return false;
    }
    Node*cur=head;
    do
    {
        if(cur->val==val)
        {
            return true;
        }
        cur=cur->next;
    }while(cur!=head);

    return false;
    
}

bool isEmpty()
{

    if(head==nullptr)
    {
        return true;
    }
    else return false;
}

void Size()
{
    int count=0;
    if(head==nullptr)
    {
        std::cout<<"The list is Emptry!\n";
        return;
    }

    Node* temp=head;
    do
    {
        temp=temp->next;
        count++;

    } while (temp!=head);
    std::cout<<"\n"<<count<<" elements in the list \n";
}

void Clear()
{
    if(head==nullptr)
    {
        std::cout<<"List is Emptry\n";
        return;
    }

    Node*last=head;
    while(last->next!=head)
    {
        last=last->next;
    }
    last->next=nullptr;

    Node*cur=head;
    while(cur!=nullptr)
    {
        Node*temp=cur->next;
        delete cur;
        cur=temp;
    }

    head=nullptr;

}

};


int main()
{
    Clist lst;
    if(lst.isEmpty())
    {
        std::cout<<"List is Empty\n";
    }
    
    
    lst.append(1);
    lst.append(2);
    lst.prepend(0);
    std::cout<<"It is display before remove\n";
    lst.display();
    lst.remove(0);
    std::cout<<"It is display after remove\n";
    lst.display();
    std::cout<<lst.search(1);
    lst.Size();
    

    lst.Clear();
    lst.display();
    
    return 0;
}