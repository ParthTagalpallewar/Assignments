#include <iostream>
using namespace std;
#define size 50

class Operation;

class Stack1
{
private:
	int top;
	char stack[size];

public:
	Stack1()
	{
		top=-1;
	}
	void push(char);
	void pop();
	char topEle();
	bool isEmpty();

    friend class Operation;
    
};

class Stack2
{

private:
	int top;
	int stack[size];

public:
	Stack2()
	{
		top=-1;
	}
	void push(int);
	void pop();
	int topEle();
	bool isEmpty();
};

class Operation
{
    string postFixExp="";
    public:
    int precedence(char);
    void infixToPostfix(string,Stack1&);
    void evaluatePostfix(Stack2&);
};

void Stack1::push(char ele)
{
	if(top!=(size-1))
	{
		top++;
		stack[top]=ele;
	}
}

void Stack1::pop()
{
	if(top!=-1)
	{
		// stack[top]=-1;
        top--;
	}
}

char Stack1::topEle()
{
	return stack[top];
}

bool Stack1::isEmpty()
{
	if(top==-1) { return true; }
	else        { return false; }
}

void Stack2::push(int ele)
{
	if(top!=(size-1))
	{
		top++;
		stack[top]=ele;
	}
}

void Stack2::pop()
{
	if(top!=-1)
	{
		// stack[top]=-1;
        top--;
	}
}

int Stack2::topEle()
{
	return stack[top];
}

bool Stack2::isEmpty()
{
	if(top==-1) { return true; }
	else        { return false; }
}

int Operation::precedence(char ch)
{
    if (ch=='/' || ch=='*') 
    {
       return 2;
    }
    else
    {
        return 1;
    }
}

void Operation::infixToPostfix(string expression,Stack1& s)
{
    for(int i=0;i<expression.length();i++)
    {
        char ch=expression[i];
        if(ch=='(')
        {
            s.push(ch);
        }
        else if(ch==')')
        {
            while(s.stack[s.top]!='(')
            {
                postFixExp=postFixExp+s.stack[s.top];
                s.pop();
            }
            s.pop();
        }
        else if(ch=='/' || ch=='*' || ch=='+' || ch=='-')
        {
            while((!s.isEmpty()) && (s.stack[s.top]!='(') && (precedence(ch)<=precedence(s.stack[s.top])))
            {
                postFixExp=postFixExp+s.stack[s.top];
                s.pop();
            }
            s.push(ch);
        }
        else
        {
            postFixExp=postFixExp+ch;
        }
    }
    while(!s.isEmpty())
    {
        postFixExp=postFixExp+s.stack[s.top];
        s.pop();
    }

    cout<<"Infix to Postfix Expression : "<<postFixExp<<endl;
}

void Operation::evaluatePostfix(Stack2& s)
{
    for(int i=0;i<postFixExp.length();i++)
    {
        char ch=postFixExp[i];

        if(ch=='/' || ch=='*' || ch=='+' || ch=='-')
        {
            int A=s.topEle(); 
            s.pop();
            int B=s.topEle(); 
            s.pop();

            int val;
            switch(ch)
            {
                case '/': val=B/A; break;
                case '*': val=B*A; break;
                case '+': val=B+A; break;
                case '-': val=B-A; break;
            }
            s.push(val);
        }
        else
        {
            s.push(ch-48);
        }
    }
    cout<<"Value of the Postfix Expression : "<<s.topEle()<<endl;
}

int main()
{
    Stack1 s1;
    Stack2 s2;
    Operation o1;

    string expression;
    char choice='y';

    while(choice=='y')
    {
        cout<<"\nEnter a valid paranthesis expression : ";
        cin>>expression;
        o1.infixToPostfix(expression,s1);
        o1.evaluatePostfix(s2);

        cout<<"\nDo you want to repeat ? (y/n) : ";
        cin>>choice;

        try
        {
            if (choice!='y' && choice!='n')
            {
                throw choice;
            }
        }
        catch(int x)
        {
            cout<<"\nInvalid Input !"<<endl;
        }
    }
    cout<<"\n********** Thank you **********\n"<<endl;
	return 0;
}