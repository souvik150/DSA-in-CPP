// Pointers are variables which store address of other variables

#include <iostream>
using namespace std;

int main()
{
  int i = 9;
  cout << &i << endl;

  int *p = &i;

  // Below will print the adress of the variable
  cout << p << endl;

  // Below will print the data which the adress points to
  cout << *p << endl;

  float f = 10.2f;
  float *pf = &f;
  cout << pf << endl;
  cout << *pf << endl;

  double d = 122.32;
  double *pd = &d;
  cout << pd << endl;
  cout << *pd << endl;

  return 0;
}
