#include <iostream>
using namespace std;

int main()
{
  int i = 9;
  int *p = &i;

  cout << sizeof(p) << endl;

  cout << i << endl;
  cout << *p << endl;

  i++;

  cout << i << endl;
  cout << *p << endl;

  // int a = i;
  // a++;

  int a = *p;
  a++;

  cout << a << endl;
  cout << *p << endl;

  return 0;
}
