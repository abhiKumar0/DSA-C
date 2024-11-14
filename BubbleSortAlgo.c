#include <stdio.h>

void printArr(int *A, int n) {
  for (int i = 0; i<n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
};

void bubbleSort(int *A, int n) {
  int temp;
  for (int i = 0; i < n-1; i++) {
    printf("The number of passes %d \n", i+1);
    for (int j = 0; j < n-1-i; j++) {
      if(A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
}

void bubbleSortAdaptive(int *A, int n) {
  int temp;
  int isSorted = 0;
  for (int i = 0; i< n-1; i++) {
    isSorted = 1;
    printf("The number of passes %d \n", i+1);
    for (int j = 0; j<n-1-i; j++) {
      if(A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
        isSorted = 0;
      }
    }
    if(isSorted) {
      return;
    }
  }
}



int main() {
  int A[] = {2, 3, 6, 4, 8, 9};
  // int A[] = {1, 2, 3, 4, 5, 6};
  int n = 6;
  printArr(A, n);
  bubbleSortAdaptive(A, n);
  printArr(A, n);

  return 0;
}


/*
  Bubble Sort Algorithm

  1. Stable
  2. (n-1) passes
  3. O(n2) time complexity

*/