#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findFloor(vector<int> &v, int x)
{
  int a = v[0];
  int index=  -1;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] >= a && v[i] < x)
    {
      index = i;
    }
  }
  return index;
}

int main()
{
  vector<int> v = {2, 4, 6, 1, 7};
  cout<<findFloor(v, 7);

  return 0;
}