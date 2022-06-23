#include <iostream>
using namespace std;

int main()
{
  int a[10];

  // Both of the below print the same
  cout << a << endl;
  cout << &a << endl;

  a[0] = 12;
  cout << &a[0] << endl;

  cout << a[0] << endl;

  int *p = &a[0];

  // Address of a
  cout << p << endl;

  // Address of a+8
  cout << &p << endl;

  // Value stored at a[0]
  cout << *p << endl;

  cout << p << endl;
  p = p + 1;
  cout << p << endl;

  // a cannot be reassigned
  // a = a + 1;

  return 0;
}