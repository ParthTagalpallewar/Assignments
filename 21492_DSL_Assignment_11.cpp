#include<iostream>
using namespace std;

class Job
{
    int job[5];
    int rear;
    int front;

    public:
    Job()
    {
        rear=-1;
        front=-1;
    }

    void enqueue(int);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();

};

void Job::enqueue(int item)
{
    if(front==-1)
    {
        front=0;
    }
    rear++;
    job[rear]=item;
}

void Job::dequeue()
{
        // job[front]=-1;
        front++;
}

bool Job::isEmpty()
{
    if ((front==-1) || (front==rear+1)) 
        { return 1; }
    else
        { return 0; }
}

bool Job::isFull()
{
    if ((front==0) && (rear==4))
        { return 1; }
    else
        { return 0; }
}

void Job::display()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<job[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Job j;
    cout<<"\n<----------Menu---------->"<<endl;
    cout<<"1-Insertion"<<endl;
    cout<<"2-Deletion"<<endl;
    cout<<"3-Display"<<endl;
    cout<<"4-Exit"<<endl;

    char option='y';
    int choice;
    do
    {
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1: if(j.isFull())
                {
                    cout<<"Overflow !"<<endl;
                }
                else
                {
                int item;
                cout<<"\nEnter the job code : ";
                cin>>item;
                j.enqueue(item);
                }
                break;

        case 2: if (j.isEmpty())
                {
                    cout<<"\nUnderflow !"<<endl;
                }
                else
                {
                 j.dequeue();
                }
                break;

        case 3: if(j.isEmpty())
                    { cout<<"No job available !"<<endl; }
                else
                    { j.display(); }
                break;
        }
        
    } while (choice!=4);
    return 0;
}