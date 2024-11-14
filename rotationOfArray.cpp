#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rotateRight(vector<int>& nums, int k ){
  if (k <= 0) return;
  int temp;
  int n = nums.size();
  // for (int i= 0; i < n-1; i++) {
  //   if (nums[i+1] > nums[i]) {
  //     temp = nums[i];
  //     nums[i] = nums[i+1];
  //     nums[i+1] = temp;
  //   }
  // }
  // rotateRight(nums, k-1);
}

int main() 
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  rotateRight(nums, k);
  for (int i : nums){
    cout << i << " ";
  }

  return 0;
}