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

void countSort(vector<int> &A)
{
  //Max value of the given array
  int x = *max_element(A.begin(), A.end());
  //Initializing a new array with each element being 0
  vector<int> B(x + 1, 0); 
  int i;
  //Increamenting the index where the element is found
  for (i = 0; i < A.size(); i++)
  {
    B[A[i]]++;
  }
  //clearing the main array
  A.clear();
  i = 0;
  //Pushing back the element in the main array according the index of second array
  while (i <= x)
  {
    if (B[i] > 0)
    {
      A.push_back(i);
      B[i]--;
    }
    else
    {
      i++;
    }
  }
}

int main()
{
  vector<int> a = {23, 4, 5, 76, 89, 2, 11, 45, 7, 2, 8, 4, 23, 16, 55};
  int x = *max_element(a.begin(), a.end());
  countSort(a);
  for (auto i : a)
  {
    cout << i << " ";
  }

  return 0;
}