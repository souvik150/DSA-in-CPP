#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
  int key;
  int j;

  for (int i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && key < arr[j])
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  int arr[] = {1, 2, 7, 5, 3, 6, 9, 8};
  int size = 8;

  InsertionSort(arr, size);

  for (int i = 0; i < 8; i++)
  {
    cout << arr[i] << " ";
  }
}