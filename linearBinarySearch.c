#include <stdio.h>

//Linear search for unsoted array

int linearSearch(int arr[], int size, int element){
  for (int i=0; i<size; i++){
    if (arr[i] == element) {
      return i;
    }
  }
  return -1;
}

//Binary search for sorted array
int binarySearch(int arr[], int size, int element) {
  int low, mid, high;
  low = 0;
  high = size - 1;
  while (low <= high) {
    mid = (low + high)/2;
    if (arr[mid] == element) {
      return mid;
    }
    if(arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}


int main() {
  // int arr[] = {12,2, 34, 5, 4, 1, 54, 6, 87, 77, 65, 90};
  // int size = sizeof(arr)/sizeof(int);
  
  int arr[] = {2,12, 34, 45, 54, 61, 74, 86, 87, 177, 265, 590};
  int size = sizeof(arr)/sizeof(int);
  int element = 54;
  // int searchedIndex = linearSearch(arr, size, element);
  int searchedIndex = binarySearch(arr, size, element);
  printf("The element %d was found at index %d \n", element, searchedIndex);
  return 0;
}