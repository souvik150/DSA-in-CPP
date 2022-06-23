// Program starts with stack memory and is less whereas heap memory is large. When we write int i = 10; it is stored in stack memory and uses it.

// Static memory automatically releases in the basis of scope
// Dynamic memory manually release is required

#include <iostream>
using namespace std;

int main()
{
  int *p = new int;
  *p = 10;

  cout << *p << endl;

  // double *pd = new double;
  // char *c = new char;

  // int *pa = new int[50];

  int n;
  cin >> n;
  int *pa2 = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> pa2[i];
  }
  int max = -1;
  for (int i = 0; i < n; i++)
  {
    if (max < pa2[i])
    {
      max = pa2[i];
    }
  }
  cout << max << endl;

  int *p = new int;
  delete p;

  p = new int[100];
  delete[] p;

  return 0;
}