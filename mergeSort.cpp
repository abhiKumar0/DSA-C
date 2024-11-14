#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void pr(vector<int> A)
{
  for (int a : A)
  {
    cout << a << " ";
  }
  cout << endl;
}

void merge(vector<int> &A, int low, int mid, int high)
{
  int i, j, k;
  vector<int> B;
  i = low;
  j = mid + 1;
  // Merge the two halves into B
  while (i <= mid && j <= high)
  {
    if (A[i] < A[j])
    {
      B.push_back(A[i]);
      i++;
    }
    else
    {
      B.push_back(A[j]);
      j++;
    }
  }

  // Append remaining elements from left half
  while (i <= mid)
  {
    B.push_back(A[i]);
    i++;
  }

  // Append remaining elements from right half
  while (j <= high)
  {
    B.push_back(A[j]);
    j++;
  }

  // Copy merged elements back to the original array
  for (int k = 0; k < B.size(); k++)
  {
    A[low + k] = B[k];
  }
}

void mergeSort(vector<int> &A, int low, int high)
{
  // pr(A);
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    // cout << low<<" "<< mid<< " " << high<<endl;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
    // pr(A);
  }
}

int main()
{
  vector<int> A = {23, 4, 5, 76, 89, 2, 11, 45, 7, 2, 8, 4, 23, 16, 55};

  mergeSort(A, 0, A.size() - 1);
  pr(A);
  // for (int a : A)
  // {
  //   cout << a << " ";
  // }

  return 0;
}