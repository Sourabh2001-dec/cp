// 20. Maximum profit by buying and selling a share at most twice.
// [ Practice here : https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/ ]
#include <bits/stdc++.h>
using namespace std;

// (valley peak approach) - works if there are infinite transactions
// int maxProfit(vector<int> &prices)
// {
//   int minima = prices[0];
//   int maxima = 0;
//   bool isRising = prices[1] > prices[0];
//   set<int, greater<int>> profits;

//   for (int i = 0; i < prices.size(); i++)
//   {
//     while (prices[i + 1] < prices[i])
//     {
//       i++;
//     }
//     minima = prices[i];

//     while (prices[i + 1] > prices[i])
//     {
//       i++;
//     }

//     maxima = prices[i];

//     profits.insert(maxima - minima);
//   }

//   auto j = profits.begin();
//   int first = *j;
//   int second = ++j != profits.end() ? *j : 0;
//   return first + second;
// }

int maxProfit(vector<int> &prices)
{
  vector<int> profit(prices.size(), 0);
  int n = prices.size();
  int maxPrice = prices[n - 1];

  for (int i = n - 1; i >= 0; i--)
  {
    maxPrice = max(maxPrice, prices[i]);

    profit[i] = max(profit[i + 1], maxPrice - prices[i]);
  }

  int minPrice = prices[0];
  for (int i = 1; i < n; i++)
  {
    minPrice = min(minPrice, prices[i]);

    profit[i] = max(profit[i - 1], profit[i] + prices[i] - minPrice);
  }

  return profit[n - 1];
}

int main(int argc, char const *argv[])
{
  vector<int> prices = {5, 100, 30, 15, 10, 8, 25, 80};
  cout << maxProfit(prices);
  return 0;
}
