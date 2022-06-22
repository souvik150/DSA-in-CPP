#include <iostream>
using namespace std;

int main()
{
  int a[10];
  cout << &a[0] << endl;

  a[0] = 5;
  a[1] = 10;

  cout << *a << endl;
  cout << *(a + 1) << endl;

  int z[5];
  int *c;
  cout << sizeof(z) << " " << sizeof(c) << endl;

  int m[6] = {1, 2, 3};
  int *b = m;
  cout << b[2] << endl;

  int l[] = {1, 2, 3, 4, 5};
  cout << *(l) << " " << *(l + 4);
  

  return 0;
}