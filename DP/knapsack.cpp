// knapsack problem using recursion
#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<pair<ll, ll>, ll> memo;

ll knapsack(vector<ll> wt, vector<ll> val, ll W, ll N)
{
  if (W == 0 || N == 0)
  {
    return 0;
  }

  if (memo[make_pair(W, N)])
  {
    return memo[make_pair(W, N)];
  }

  if (wt[N - 1] <= W)
  {
    ll value = max(val[N - 1] + knapsack(wt, val, W - wt[N - 1], N - 1), knapsack(wt, val, W, N - 1));
    return memo[make_pair(W, N)] = value;
  }
  else
  {
    ll value = knapsack(wt, val, W, N - 1);
    return memo[make_pair(W, N)] = value;
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
  for (ll i = 1; i <= W; i++)
  {
    /* code */
    cout << knapsack(wt, val, i, N) << " ";
  }

  return 0;
}
