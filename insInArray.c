#include <stdio.h>

int insertFunc (int arr[], int element, int tSize, int uSize, int index) {
  if (index >= tSize) {
    return -1;
  }

  for (int i = uSize; i>=index; i--){
    arr[i+1] = arr[i];
  }
  arr[index] = element;
  return 1;
}

void show (int arr[], int uSize) {
  for (int i = 0; i<uSize; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int deleteFunc (int arr[], int element, int uSize) {
  int index;
  for (int i = 0; i<uSize; i++){
    if (arr[i] == element){
      index = i;
    }
  }

  for (int i = index; i<uSize; i++) {
    arr[i] = arr[i + 1];
  }

  return 1;
}

int main() {
  int arr[100] = {2, 3, 4, 34, 67, 99};
  int uSize = 6, element = 20, index = 3;
  show(arr, uSize);
  int insArr = insertFunc(arr, element, 100, uSize, index);
  uSize += 1;
  if (insArr == 1) {
    show(arr, uSize);
  };

  int delArr = deleteFunc(arr, 34, uSize);
  uSize -= 1;
  if (delArr == 1){
    show(arr, uSize);
  }
}