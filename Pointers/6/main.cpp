#include <iostream>
using namespace std;

int main()
{
  char str[] = "abcde";

  // Below is pointing to temporary memory
  // char *psff = "abcde";

  cout << str << endl;

  int a[] = {1, 2, 3};
  char b[] = "abc";

  // Print Address
  cout << a << endl;
  // Prints the array
  cout << b << endl;

  char *c = &b[0];
  cout << c << endl;

  char c1 = 'a';
  char *pc = &c1;

  cout << c1 << endl;
  cout << pc << endl;

  char ch = 'a';
  char *ptr = &ch;
  ch++;
  cout << *ptr << endl;
  
  char p[] = "xyz";
  cout<<p[0]<<endl;

  char *k = &p[0];
  k++;
  cout << k << endl;

  char s[] = "hello";
  char *h = s;
  cout << s[0] << " " << h[0];

  return 0;
}