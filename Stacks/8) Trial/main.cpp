// #include <iostream>
// #include <climits>
// using namespace std;

// // ! Statically Allocated Stack

// class StackUsingArray
// {
//   int *data;
//   int nextIndex;
//   int capacity;

// public:
//   StackUsingArray(int totalSize)
//   {
//     data = new int[totalSize];
//     nextIndex = 0;
//     capacity = totalSize;
//   }

//   int size()
//   {
//     return nextIndex;
//   }

//   bool isEmpty()
//   {
//     return nextIndex == 0;
//   }

//   void push(int element)
//   {
//     if (nextIndex == capacity)
//     {
//       cout << "Stack Full!" << endl;
//     }
//     else
//     {
//       data[nextIndex] = element;
//       nextIndex++;
//     }
//   }

//   int pop()
//   {
//     if (isEmpty())
//     {
//       cout << "Stack Empty!" << endl;
//       return INT_MIN;
//     }
//     nextIndex--;
//     return data[nextIndex];
//   }

//   int top()
//   {
//     if (isEmpty())
//     {
//       cout << "Stack Empty!" << endl;
//       return INT_MIN;
//     }
//     return data[nextIndex - 1];
//   }
// };

// //! Dynamically allocated  stack

// class DynamicStack
// {
//   int *data;
//   int nextIndex;
//   int capacity;

// public:
//   DynamicStack()
//   {
//     data = new int[4];
//     nextIndex = 0;
//     capacity = 4;
//   }

//   int size()
//   {
//     return nextIndex;
//   }

//   bool isEmpty()
//   {
//     return nextIndex == 0;
//   }

//   void push(int element)
//   {
//     if (nextIndex == capacity)
//     {
//       int *neData = new int[2 * capacity];
//       for (int i = 0; i < capacity; i++)
//       {
//         neData[i] = data[i];
//       }
//       capacity *= 2;
//       delete[] data;
//       data = neData;
//     }
//     data[nextIndex] = element;
//     nextIndex++;
//   }

//   int pop()
//   {
//     if (isEmpty())
//     {
//       cout << "Stack Empty!" << endl;
//       return INT_MIN;
//     }
//     nextIndex--;
//     return data[nextIndex];
//   }

//   int top()
//   {
//     if (isEmpty())
//     {
//       cout << "Stack Empty!" << endl;
//       return INT_MIN;
//     }
//     return data[nextIndex - 1];
//   }
// };

// int main()
// {
//   StackUsingArray s(4);
//   s.push(10);
//   s.push(20);
//   s.push(30);
//   s.push(40);
//   s.push(50);

//   cout << s.top() << endl;
//   cout << s.pop() << endl;
//   cout << s.pop() << endl;
//   cout << s.pop() << endl;

//   cout << s.size() << endl;

//   cout << s.isEmpty() << endl;

//   cout << "---------------------------------------" << endl;

//   DynamicStack s1;
//   s1.push(10);
//   s1.push(20);
//   s1.push(30);
//   s1.push(40);
//   s1.push(50);
//   s1.push(60);

//   cout << s1.top() << endl;
//   cout << s1.pop() << endl;
//   cout << s1.pop() << endl;
//   cout << s1.pop() << endl;

//   cout << s1.size() << endl;

//   cout << s1.isEmpty() << endl;
// }
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int isOperand(char x)
{
  if (x == '+' || x == '-' || x == '*' || x == '/' ||
      x == '^' || x == '(' || x == ')')
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
  char *postfix = new char[strlen(infix) + 1];

  stack<char> stk;

  int i = 0;
  int j = 0;

  while (infix[i] != '\0')
  {
    if (isOperand(infix[i]))
    {
      postfix[j++] = infix[i++];
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
        stk.pop();
      }
    }
  }

  while (!stk.empty() && stk.top() != ')')
  {
    postfix[j++] = stk.top();
    stk.pop();
  }

  postfix[j] = '\0';

  return postfix;
}

int main()
{

  char infix[] = "((a+b)*c)-d^e^f";

  cout << convert(infix) << endl;
}