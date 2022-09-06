void merge(int *part1, int size1, int *part2, int size2, int *output, int n)
{
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < size1 && j < size2)
  {
    if (part1[i] < part2[j])
    {
      output[k++] = part1[i++];
    }
    else
    {
      output[k++] = part2[j++];
    }
  }

  while (j < size2)
  {
    output[k++] = part2[j++];
  }
  while (i < size1)
  {
    output[k++] = part1[i++];
  }
}

void mergeSort(int arr[], int size)
{
  if (size == 1)
  {
    return;
  }

  int *part1 = new int[size / 2];
  int size1 = size / 2;
  int *part2 = new int[size - size / 2];
  int size2 = size - size / 2;

  for (int i = 0; i < size1; i++)
  {
    part1[i] = arr[i];
  }

  int k = 0;

  for (int i = size1; i < size; i++)
  {
    part2[k++] = arr[i];
  }

  mergeSort(part1, size1);
  mergeSort(part2, size2);
  merge(part1, size1, part2, size2, arr, size);
}

int partition(int input[], int start, int end)
{

  int pivot = input[start];
  int count = 0;

  for (int i = start + 1; i <= end; i++)
  {

    if (input[i] <= pivot)
    {
      count++;
    }
  }

  int pivotIndex = start + count;

  int temp = input[start];
  input[start] = input[pivotIndex];
  input[pivotIndex] = temp;

  int i = start;
  int j = end;

  while (i < pivotIndex && j > pivotIndex)
  {
    if (input[i] <= pivot)
    {
      i++;
    }
    else if (input[j] > pivot)
    {
      j--;
    }
    else
    {
      int temp = input[i];
      input[i] = input[j];
      input[j] = temp;
      i++;
      j--;
    }
  }

  return pivotIndex;
}

void QuickSort(int input[], int start, int end)
{
  if (start >= end)
  {
    return;
  }
  int p = partition(input, start, end);
  QuickSort(input, start, p - 1);
  QuickSort(input, p + 1, end);
}

void quickSort(int input[], int size)
{
  if (size <= 1)
    return;
  int start = 0, end = size - 1;
  QuickSort(input, start, end);
}