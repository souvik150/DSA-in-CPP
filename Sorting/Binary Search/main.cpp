#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
  int start = 0;
  int end = n - 1;
  int mid = 0;

  while (start <= end)
  {

    mid = (start + end) / 2;
    if (val < input[mid])
    {
      end = mid - 1;
    }
    else if (val > input[mid])
    {
      start = mid + 1;
    }
    else if (input[mid] == val)
    {
      return mid;
    }
  }
  return -1;
}
int main()
{

  int size;
  cin >> size;
  int *input = new int[size];

  for (int i = 0; i < size; ++i)
  {
    cin >> input[i];
  }

  int t;
  cin >> t;

  while (t--)
  {
    int val;
    cin >> val;
    cout << binarySearch(input, size, val) << endl;
  }

  delete[] input;
  return 0;
}