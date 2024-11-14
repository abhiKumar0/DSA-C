#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
  vector<int> a = {1,2,3,4};
  vector<int> b = {5,4,6,7,5,3,2};
  a.swap(b);
  for (int i: a) {
    cout<<i<<" ";
  }
  return 0;
}
