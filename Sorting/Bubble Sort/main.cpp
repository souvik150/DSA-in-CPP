#include <iostream>
using namespace std;

int main()
{
  int input[] = {10, 4, 8, 2, 4, 6};
  int size = 6;

  for (int j = 0; j < size - 1; j++)
  {
    for (int i = 0; i < size - 1 - j; i++)
    {
      if (input[i] > input[i + 1])
      {
        int temp = input[i];
        input[i] = input[i + 1];
        input[i + 1] = temp;
      }
    }
  }

  for (int i = 0; i < size; i++)
  {
    cout << input[i] << " ";
  }
}