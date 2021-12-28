// knapsack problem using top down
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void knapsack(vector<ll> wt, vector<ll> val, ll W, ll N)
{
  vector<vector<ll>> topDownArr(N + 1, vector<ll>(W + 1));

  ll rows = N + 1;
  ll cols = W + 1;
  for (ll n = 1; n < rows; n++)
  {
    for (ll w = 1; w < cols; w++)
    {
      if (wt[n - 1] <= w)
      {
        // choose
        ll val1 = val[n - 1] + topDownArr[n - 1][w - wt[n - 1]];
        ll val2 = topDownArr[n - 1][w];
        topDownArr[n][w] = max(val1, val2);
      }
      else
      {
        // reject
        topDownArr[n][w] = topDownArr[n - 1][w];
      }
    }
  }
  for (ll i = 1; i < W + 1; i++)
  {
    /* code */
    cout << topDownArr[N][i] << " ";
  }
}

int main(int argc, char const *argv[])
{

  ll N, W = 0;
  cin >> N;
  vector<ll> wt;
  vector<ll> val;
  ll n = N;
  while (n--)
  {
    ll weight, value;
    cin >> weight >> value;
    W += weight;
    wt.push_back(weight);
    val.push_back(value);
  }
  knapsack(wt, val, W, N);
  return 0;
}
