#include <stdio.h>

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int partitioning(int A[], int low, int high)
{
  int pivot = A[low];
  int i = low + 1;
  int j = high;
  int temp;
  do
  {
    while (A[i] <= pivot)
    {
      i++;
    }
    while (A[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  } while (i < j);

  temp = A[low];
  A[low] = A[j];
  A[j] = temp;
  return j;
}

void quickSort(int A[], int low, int high)
{
  int partitionIndex;
  if (low < high)
  {
    partitionIndex = partitioning(A, low, high);
    quickSort(A, low, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, high);
  }
}

int main()
{
  int A[] = {23, 4, 5, 76, 89, 2, 11, 45, 7, 2, 8, 4, 23, 16, 55};
  int n = 15;
  printArray(A, n);
  quickSort(A, 0, n - 1);
  printArray(A, n);

  return 0;
}