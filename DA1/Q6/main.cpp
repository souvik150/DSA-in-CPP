#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int size = 0;

int isOperand(char x)
{
  if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
  {
    return 0;
  }
  return 1;
}

int outPrecedence(char x)
{
  if (x == '+' || x == '-')
  {
    return 1;
  }
  else if (x == '*' || x == '/')
  {
    return 3;
  }
  else if (x == '^')
  {
    return 6;
  }
  else if (x == '(')
  {
    return 7;
  }
  else if (x == ')')
  {
    return 0;
  }
  return -1;
}

int inPrecedence(char x)
{
  if (x == '+' || x == '-')
  {
    return 2;
  }
  else if (x == '*' || x == '/')
  {
    return 4;
  }
  else if (x == '^')
  {
    return 5;
  }
  else if (x == '(')
  {
    return 0;
  }
  return -1;
}

char *convert(char *infix)
{
  size = 0;
  char *postfix = new char[strlen(infix) + 1];

  stack<char> stk;

  int i = 0;
  int j = 0;

  while (infix[i] != '\0')
  {
    if (isOperand(infix[i]))
    {
      postfix[j++] = infix[i++];
      size++;
    }
    else
    {
      if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top()))
      {
        stk.push(infix[i++]);
      }
      else if (outPrecedence(infix[i]) == inPrecedence(stk.top()))
      {
        stk.pop();
      }
      else
      {
        postfix[j++] = stk.top();
        size++;
        stk.pop();
      }
    }
  }

  while (!stk.empty() && stk.top() != ')')
  {
    postfix[j++] = stk.top();
    size++;
    stk.pop();
  }

  postfix[j] = '\0';

  return postfix;
}

int calculate(char *postfix)
{
  int result = 0;

  stack<char> stk;

  for (int i = 0; i < size; i++)
  {
    if (isOperand(postfix[i]))
    {
      stk.push(postfix[i] - '0');
    }
    else
    {
      int b = stk.top();
      stk.pop();
      int a = stk.top();
      stk.pop();

      if (postfix[i] == '+')
      {
        result = a + b;
        stk.push(result);
      }
      else if (postfix[i] == '-')
      {
        result = a - b;
        stk.push(result);
      }
      else if (postfix[i] == '*')
      {
        result = a * b;
        stk.push(result);
      }
      else if (postfix[i] == '/')
      {
        result = a / b;
        stk.push(result);
      }
      else if (postfix[i] == '^')
      {
        result = a ^ b;
        stk.push(result);
      }
    }
  }

  return stk.top();
};

int main()
{

  char infix[] = "3*5+6/2-4";
  cout << convert(infix) << endl;
  cout << calculate(convert(infix)) << endl;
}