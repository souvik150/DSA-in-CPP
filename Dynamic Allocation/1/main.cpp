#include <iostream>
using namespace std;

int main()
{
  int i = 65;

  // Implicit Typecasting
  char c = i;
  cout << c << endl;

  int *p = &i;

  // Explicit Typecasting
  char *pc = (char *)p;

  cout << p << endl;
  cout << pc << endl;

  cout << *p << endl;
  cout << *pc << endl;
  cout << *(pc + 1) << endl;
  cout << *(pc + 2) << endl;
  cout << *(pc + 3) << endl;

  return 0;
}
