#include <stdio.h>


void printArr(int *A, int n) {
  for (int i = 0; i<n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
};

void selectionSort(int *A, int n) {
  int indexOfMin, temp;
  for (int i = 0; i < n-1; i++) {
    indexOfMin = i;
    for (int j = i+1; j < n; j++) {
      if (A[j] < A[indexOfMin]) {
        indexOfMin = j;
      }
    }
    //Swap A[i] and A[indexOfMin]
    temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
  }

}


int main() {
  int A[] = {21, 13, 36, 4, 18, 29};
  int n = 6;

  printArr(A, n);
  selectionSort(A, n);
  printArr(A, n);


  return 0;
}