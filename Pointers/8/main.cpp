#include <iostream>
using namespace std;

// a[] goes in as a pointer
// int sum(int a[], int size)

int sum(int *a, int size)
{
  int ans = 0;
  for (int i = 0; i < size; i++)
  {
    ans += a[i];
  }

  return ans;
}

int main()
{
  int a[6] = {0, 1, 2, 3, 4, 5};
  cout << sizeof(a) << endl;
  cout << sum(a, 6) << endl;
  cout << sum(a + 3, 3) << endl;

  return 0;
}
