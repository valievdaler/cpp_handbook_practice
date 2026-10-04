#include<iostream>

using namespace std;

template<typename T>
class List
{
    private:
    
    
    class Node
    {
        public:
        Node* pNext;
        T data;
        

        Node(T data=T(), Node*pNext=nullptr)
        {
            this->data=data;
            this->pNext=pNext;
        }
        ~Node()
        {

        }
        

    };

    Node *head;
    int Size;
    public:
        int GetSize()
        {
            return Size;
        }
        void push_back(T data)
        {
            if(head==nullptr)
            {
                head=new Node(data);
                
            }
            else
            {
                Node* current=this->head;
                while(current->pNext!=nullptr)
                {
                    current=current->pNext;
                }
                current->pNext=new Node(data);
            }
            Size++;
        }
        T &operator[](const int index)
        {
            int counter=0;
            Node* current=this->head;
            while(current!=nullptr)
            {
                if(counter==index)
                {
                    return current->data;
                }
                current=current->pNext;
                counter++;
            }
            
        }

        List()
        {
            head=nullptr;
            Size=0;
        }
        ~List()
        {

        }
};




int main()
{
    List<int> lst;
    lst.push_back(5);
    lst.push_back(69);
    cout<<"Size is "<<lst.GetSize()<<endl;;
    for(int i=0;i<lst.GetSize();i++)
    {
        cout<<i<<")";
        cout<<lst[i]<<endl;
    }
    
    return 0;
}