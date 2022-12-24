#include <bits/stdc++.h>
using namespace std;

class Stack
{
     char stack[30];
     int top;

public:
     void push(char a);
     void pop();
     void input();
};
void Stack::push(char a)
{
     top++;
     stack[top] = a;
}
void Stack::pop()
{
     top--;
}
void Stack::input()
{
     char ch[20];
     int x = 1, i = 0;
     top = -1;
     cout << "\nEnter the expression : ";
     cin >> ch;
     while (i < strlen(ch))
     {

          if ((ch[i] == '{') || (ch[i] == '[') || (ch[i] == '('))
          {
               push(ch[i]);
          }

          if ((ch[i] == '}') || (ch[i] == ']') || (ch[i] == ')'))
          {
               if (top == -1)
               {
                    cout << "\nEXPRESSION IS NOT WELL PARENTHESIZED" << endl;
                    return;
               }
               if (ch[i] == '}')
               {
                    if (stack[top] == '{')
                         pop();
                    else
                    {
                         cout << "\n Matching opening brace '{' is not found";
                    }
               }
               if (ch[i] == ']')
               {
                    if (stack[top] == '[')
                         pop();
                    else
                    {
                         cout << "\n Matching  brace '[' is not found";
                    }
               }
               if (ch[i] == ')')
               {
                    if (stack[top] == '(')
                         pop();
                    else
                    {
                         cout << "\nMatching opening brace '(' is not found";
                    }
               }
          }
          i++;
     }
     if (top == -1)
     {
          x = 5;
          cout << "\nEXPRESSION IS WELL PARENTHESIZED" << endl;
          return;
     }
     else
     {
          while (top != -1)
          {
               if (stack[top] == '[')
               {
                    pop();
                    cout << "\n Matching closing brace ']' is not found";
               }
               if (stack[top] == '{')
               {
                    pop();
                    cout << "\n Matching closing brace '}' is not found";
               }
               if (stack[top] == '(')
               {
                    pop();
                    cout << "\n Matching closing brace ')' is not found";
               }
          }

          cout << "\n EXPRESSION IS NOT WELL PARENTHESIZED" << endl;
          return;
     }
}

int main()
{
     while(true)
     {
     Stack c;
     c.input();
     }
     return 0;
}
