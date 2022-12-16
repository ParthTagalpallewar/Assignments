#include <iostream>
using namespace std;

class Binary;

class Node
{
	Node *prev;
	bool n;
	Node *next;

public:
	Node()
	{
		prev = next = NULL;
	}

	Node(bool b)
	{
		n = b;
		prev = next = NULL;
	}
	friend class Binary;
};

class Binary
{
	Node *start;
	Node *last;
	int size;

public:
	Binary()
	{
		start = NULL;
		last = NULL;
	}

	void makeBinary()
	{
		cout << "\nEnter the size of binary number : ";
		cin >> size;

		cout << "Enter each digit one by one => " << endl;
		bool bit;

		for (int i = 0; i < size; i++)
		{
			cin >> bit;
			Node *newnode = new Node(bit);
			if (start == NULL)
			{
				start = newnode;
				last = newnode;
			}
			else
			{
				last->next = newnode;
				newnode->prev = last;
				last = newnode;
			}
		}
	}

	void dispalyBinary()
	{
		Node *current;
		current = start;
		while (current != NULL)
		{
			cout << current->n;
			current = current->next;
		}
	}

	void print1sComp()
	{
		Node *current;
		current = start;
		cout << "\n1's Complement : ";
		while (current != NULL)
		{
			if (current->n == 1)
			{
				cout << 0;
			}
			else
			{
				cout << 1;
			}
			current = current->next;
		}
	}

	void print2sComp()
	{
		Node *current;
		int loc = size;
		current = last;
		cout << "\n2's Complement : ";
		while (current != NULL)
		{
			loc--;
			if (current->n == 1)
				break;
			current = current->prev;
		}

		Node *temp;
		temp = start;
		for (int i = 0; i < loc; i++)
		{
			if (temp->n == 1)
			{
				cout << 0;
			}
			else
			{
				cout << 1;
			}
			temp = temp->next;
		}

		while (current != NULL)
		{
			cout << current->n;
			current = current->next;
		}
	}

	void addAtBeg(int sum)
	{
		Node *newnode = new Node(sum);
		if (start == NULL)
		{
			start = newnode;
		}
		else
		{
			newnode->next = start;
			start->prev = newnode;
			start = newnode;
		}
	}

	void printSum(Binary &second)
	{
		Node *current1;
		Node *current2;
		current1 = last;
		current2 = second.last;

		int carry = 0;
		Binary addition;
		cout << "\n\nAddition : ";
		while (current1 != NULL)
		{
			int sum = (current1->n + current2->n + carry);
			carry = 0;
			if (sum == 2)
			{
				sum = 0;
				carry = 1;
			}
			else if (sum == 3)
			{
				sum = 1;
				carry = 1;
			}
			addition.addAtBeg(sum);
			current1 = current1->prev;
			current2 = current2->prev;
			if (current2 == NULL)
			{
				break;
			}
		}

		if (current1 == NULL)
		{
			while (current2 != NULL)
			{
				int sum = (current2->n + carry);
				carry = 0;
				if (sum == 2)
				{
					sum = 0;
					carry = 1;
				}
				addition.addAtBeg(sum);
				current2 = current2->prev;
			}
		}
		else
		{
			while (current1 != NULL)
			{
				int sum = (current1->n + carry);
				carry = 0;
				if (sum == 2)
				{
					sum = 0;
					carry = 1;
				}
				addition.addAtBeg(sum);
				current1 = current1->prev;
			}
		}
		if (carry == 1)
		{
			addition.addAtBeg(1);
		}
		addition.dispalyBinary();
	}
};

int main()
{
	char choice = 'n';
	cout << "\nFirst Binary Number => " << endl;
	Binary b1;
	b1.makeBinary();
	cout << "Binary Number : ";
	b1.dispalyBinary();

	do
	{
		cout << "\n\nEnter your choice : " << endl;
		cout << "1-->1's Complement" << endl;
		cout << "2-->2's Complement" << endl;
		cout << "3-->Addition" << endl;

		int c;
		cin >> c;

		if (c == 1)
		{
			b1.print1sComp();
		}
		else if (c == 2)
		{
			b1.print2sComp();
		}
		else if (c == 3)
		{
			cout << "\n\nSecond Binary Number => " << endl;
			Binary b2;
			b2.makeBinary();
			cout << "Second Binary Number : ";
			b2.dispalyBinary();
			b1.printSum(b2);
		}

		cout << "\n\nDo you want to quit ? (y/n) : ";
		cin >> choice;

	} while (choice == 'n');

	return 0;
}
