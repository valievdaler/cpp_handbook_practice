#include <iostream>

struct Node
{
    Node *next;
    int val;

    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front, *rear;
    public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    ~Queue()
    {
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
            std::cout<<"Added "<<val<<std::endl;
        }
        else
        {
            rear->next = newNode;
            newNode = rear;
            std::cout<<"Added "<<val<<std::endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Empty!");
        }
        else
        {
            Node *temp = front;
            front = front->next;
            std::cout << "Deleted front " << temp->val << std::endl;
            delete temp;
        }

    }

    
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(12);
    q.dequeue();
    return 0;
}