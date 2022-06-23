#include <iostream>
using namespace std;

int main()
{
  const int i = 10;
  int const i2 = 10;

  int j = 12;

  const int &k = j;

  // We can change the value with the j path but not by using the k path

  j++;
  // k++;

  cout << i << " " << k << endl;

  return 0;
}