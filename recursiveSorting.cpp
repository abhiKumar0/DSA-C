#include <iostream>

using namespace std;

void recBubbleSort(int a[], int n)
{
  if (n == 1)
    return;
  int temp;
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      temp = a[i];
      a[i] = a[i + 1];
      a[i + 1] = temp;
    };
  }
  recBubbleSort(a, n-1);
}

void insertionSort( int arr[], int n) {
  for (int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;
    while ( j>= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void recInsertionSort(int arr[], int n) {
  if (n<1) {
    return;
  }
  // cout <<n <<endl;
  recInsertionSort(arr, n-1);
  int key = arr[n];
  int j = n - 1;
  while ( j>= 0 && arr[j] > key) {
    arr[j+1] = arr[j];
    j--;
  }
  arr[j+1] = key;
}

int main()
{
  int arr[] = {4, 1, 3, 9, 7};
  int n = sizeof(arr)/sizeof(arr[0]);;
  recInsertionSort(arr, n-1);
  for (int a: arr) {
    cout << a << " ";
  }
  return 0;
}