#include <stdio.h>

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int n)
{
  int j, key;
  for (int i = 1; i < n; i++)
  {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
}

int main()
{
  // int A[] = {23, 1, 5, 54, 2, 9, 7};
  int A[] = {7, 72, 90, 21, 60};
  int n = 5;
  printArray(A, n);
  insertionSort(A, n);
  printArray(A, n);

  return 0;
}