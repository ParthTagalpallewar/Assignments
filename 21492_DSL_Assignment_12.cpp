#include <iostream>
using namespace std;
const int Max = 20;
const int limit = 5;
 
template <class T, class S>
class item
{
public:
    S item_title;
    T priority;
    item()
    {
        item_title = "";
        priority = -1;
    }
    item(S j, T p)
    {
        this->item_title = j;
        this->priority = p;
    }
    friend class Queue;
    bool operator<=(item &obj)
    {

        if (obj.priority > priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Queue
{
    item<int, string> arr[Max];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void insert_q(string name, int p)
    {
        if (rear == Max - 1)
        {
            cout << "overflow...! \n";
            return;
        }
        // item val(name,p);
        item<int, string> val(name, p);
        if (front == -1)
        {
            front++;
        }
        rear++;

        int j = rear - 1;
        while (j >= 0 && val <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
    void del()
    {
        if (front == -1)
        {
            cout << "No item entries \n";
            return;
        }
        item<int, string> item = arr[front];
        front++;
        cout << "___________: Deleted Successfully :___________\n";
        cout << "\t"
             << "item title :" << item.item_title << endl;
        cout << "\t"
             << "item Priority : " << item.priority << endl;
    }
    void display_q()
    {
        if (arr[front].priority == -1 || front == -1)
        {
            cout << "\tNo item entries " << endl;
        }
        else
        {

            cout << "________________________________________\n";
            cout << endl;
            cout << " item title  \t"
                 << "item Priority : "
                 << "\n";
            for (int i = front; i <= rear; i++)
            {
                cout << " " << arr[i].item_title << "             " << arr[i].priority << "\n";
            }
			cout << "________________________________________\n";
        }
    }
};
int main()
{
    Queue q;
    while (true)
    {
        cout << "\n____________ MENU ____________\n";
        cout << "\n1.Add the job \n2.Delete item\n3.Display item\n4.EXIT...";
		cout << "\n______________________________\n";
        int o;
        cout << "Enter Choice : \n";
        cin >> o;
        if (o == 1)
        {
            string s;
            cout << "Enter the name of job : " << endl;
            cin >> s;
            int n;
            cout << "Enter its priority : " << endl;
            cin >> n;
            q.insert_q(s, n);
            cout << "\nSelected Successfully !\n";
            
        }
        else if (o == 2)
        {
            q.del();
        }
        else if (o == 3)
        {
            q.display_q();
        }
        else if (o == 4)
        {
            cout << "--->Thanks for using program <---" << endl;
            break;
        }
        else
        {
            cout << "INVALID CHOICE...!" << endl;
        }
    }
    return 0;
}