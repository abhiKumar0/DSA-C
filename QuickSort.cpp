#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &A, int low, int high)
{
  int pivot = A[low];
  int i = low + 1;
  int j = high;
  int temp;
  do
  {
    while (A[i] < pivot)
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

void quickSort(vector<int> &A, int low, int high)
{
  int partitionIndex;
  if (low < high)
  {
    partitionIndex = partition(A, low, high);
    quickSort(A, low, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, high);
  }
}

int main()
{
  vector<int> A = {23, 1, 5, 2, 65, 34, 6, 34, 9, 45};
  int n = A.size();
  // sort(A.begin(), A.end()-1);
  quickSort(A, 0, n - 1);
  for (int a : A)
  {
    cout << a << " ";
  }
  // cout <<n;
  return 0;
}