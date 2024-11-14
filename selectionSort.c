#include <stdio.h>


void printArray(int A[], int n) {
  for (int i = 0; i<n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void selectionSort(int A[], int n)
{
  int indexOfMin, temp;
  for (int i = 0; i < n-1; i++) {
    indexOfMin = i;
    for (int j = i+1; j < n; j++) {
      if(A[j] < A[indexOfMin]) {
        indexOfMin = j;
      }
    }
    temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
  }
}


int main()
{

  int A[] = {23, 4, 5, 76, 89, 2, 11, 45, 7, 2, 8, 4, 23, 16, 55};
  int n = 15;
  printArray(A, n);
  selectionSort(A, n);
  printArray(A, n);

  return 0;
}