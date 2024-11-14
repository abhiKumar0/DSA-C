#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
  int maxProfitVal = 0;
  
  int a= 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++){
      if (prices[j] - prices[i] > maxProfitVal) {
        maxProfitVal = prices[j]-prices[i];
      }
    }
    // if (prices[i] < lowerValue)
    // {
    //   lowerValue = prices[i];
    //   lowerIndex = i;
    // }
  }
  // cout << "li "<< n<<endl;
  // if (lowerIndex == n - 1)
  // {
  //   return 0;
  // }

  // for (int i = lowerIndex; i < n; i++)
  // {
  //   if (prices[i] - prices[lowerIndex] > maxProfitVal)
  //   {
  //     cout<<"i-l "<<prices[i] - prices[lowerIndex]<<endl;
  //     maxProfitVal = prices[i] - prices[lowerIndex];
  //   }
  // }

  return maxProfitVal;
}

int main()
{

  vector<int> p = {2, 1};
  cout << "Maximum Profit: " << maxProfit(p) << endl;

  return 0;
}