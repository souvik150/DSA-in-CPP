#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{
  int j = 1;
  for (int i = 0; i < n; i++)
  {
    arr[i] = j++;
    arr[n - i - 1] = j++;
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int *arr = new int[n];
    arrange(arr, n);
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
  }
}
