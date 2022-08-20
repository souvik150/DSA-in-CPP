#include <iostream>
using namespace std;

void SelectionSort(int data[], int size)
{
  int smallEl;
  int index;

  for (int j = 0; j < size; j++)
  {
    smallEl = data[j];
    index = j;

    for (int i = j; i < size; i++)
    {
      if (data[i] < smallEl)
      {
        smallEl = data[i];
        index = i;
      }
    }

    int temp = data[index];
    data[index] = data[j];
    data[j] = temp;
  }
}

int main()
{

  int arr[] = {2, 6, 1, 8, 2, 7};

  SelectionSort(arr, 6);

  for (int i = 0; i < 6; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}