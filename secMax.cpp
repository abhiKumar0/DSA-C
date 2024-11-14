#include <iostream>
#include <limits>

using namespace std;

int secMax(int ar[], int n) {
  int i, max, sm;
  max = -1000; 
  sm = -1000;
  for (i= 0; i<n; i++) {
    if (ar[i] > max) {
      sm = max;
      max = ar[i];
    } else if (ar[i] > sm && ar[i] != max) {
      sm = ar[i];
    }
  }
  return sm;
}

int main(){
  int a[] = {3, 4,5,2,1,5};
  cout<<secMax(a, 7)<<endl;

  return 0;
}