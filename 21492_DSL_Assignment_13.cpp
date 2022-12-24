#include<iostream>
#define size 5
using namespace std;

class Deque
{
    int front, rear;
    int deque[size];
    
    public:

    Deque()
    {
        front = rear =-1;
    }

    void enqueFront();
    void enqueRear();
    void dequeFront();
    void dequeRear();
    void display();
    bool isEmpty();
    bool isFull();
};

void Deque::enqueFront()
{
    if(isFull())
    {
        cout<<"Overflow !"<<endl;
    }
    else
    {
        int element;
        cout<<"\nEnter the element : ";
        cin>>element;
        cout<<"Element inserted successfully."<<endl;

        if(isEmpty()) 
        {
            front=0;
            rear=0;
            deque[front]=element;
        }
        else if(front==0)
        {
            front=size-1;
            deque[front]=element;
        }
        else
        {
            front--;
            deque[front]=element;
        }
    }
}

void Deque::enqueRear()
{
    if(isFull())
    {
        cout<<"Overflow !"<<endl;
    }
    else
    {
        int element;
        cout<<"\nEnter the element : ";
        cin>>element;
        cout<<"Element inserted successfully."<<endl;

        if(isEmpty())
        {
            front=0;
            rear=0;
            deque[rear]=element;
        }
        else if(rear==(size-1))
        {
            rear=0;
            deque[rear]=element;
        }
        else
        {
            rear++;
            deque[rear]=element;
        }
    }
}

void Deque::dequeFront()
{
    if(isEmpty())
    {
        cout<<"Underflow !"<<endl;
    }
    else
    {
        if (front==rear)
        {
            front=rear=-1;
        }
        else if(front==(size-1))
        {
            front=0;
        }
        else
        {
            front++;
        }
        cout<<"Element deleted successfully."<<endl;
    }  
}

void Deque::dequeRear()
{
    if(isEmpty())
    {
        cout<<"Underflow !"<<endl;
    }
    else
    {
        if (front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }
        cout<<"Element deleted successfully."<<endl;
    }  
}

void Deque::display()
{
    if(isEmpty())
    {
        cout<<"Deque is Empty !"<<endl;
    }
    else
    {
        cout<<"Deque : ";
        int i=front;
        while(i!=rear)
        {
            printf("%d ",deque[i]); 
            i=(i+1)%size;
        }
        printf("%d",deque[rear]);
        cout<<endl;
    }
}

bool Deque::isEmpty()
{
    if((front==-1) && (rear==-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Deque::isFull()
{
    if ((front==0 && rear==(size-1)) || (front==rear+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Deque d;

    while(true)
    {
    cout<<"\n************* Menu *************\n"<<endl;
    cout<<"1.Insertion from front"<<endl;
    cout<<"2.Insertion from rear"<<endl;
    cout<<"3.Deletion from front"<<endl;
    cout<<"4.Deletion from rear"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Quit"<<endl;
    cout<<"\n********************************"<<endl;

    int choice;
    cout<<"\nEnter your choice : ";
    cin>>choice;

    try 
    {
        if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6)
        {
            throw choice;
        }
    }
    catch (int x) 
    {
        cout<<"\nInvalid Input !"<<endl;
        continue;
    }

    switch(choice)
    {
        case 1: d.enqueFront(); 
                break;

        case 2: d.enqueRear();
                break;

        case 3: d.dequeFront();     
                break;

        case 4: d.dequeRear(); 
                break;

        case 5: d.display(); 
                break;
    }

    if (choice==6)
    {
        cout<<"\n*********** Thank You ***********\n"<<endl;
        break;
    }

    }
    return 0;
}
