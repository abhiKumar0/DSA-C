#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> a, int t) {
  vector<int> b;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      if (a[i] + a[j] == t) {
        b.push_back(i);
        b.push_back(j);
        return b;
      }
    }
  }
}

int main() {


  return 0;
}