/*
Сука блять
*/
#include <bits/stdc++.h>
#define ll long long
#define rep(i, m, n) for (ll i = m; i <= n; i++)
#define reb(i, m, n) for (ll i = m; i >= n; i--)
#define rv(i, vt) for (auto i : vt)
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
using namespace std;
const ll N = 1e6 + 5;
ll n, k, a[N], b[N];
void solo()
{
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	k = 0;
	rep(i, 1, n)
	{
		cin >> b[i];
		k = max(k, a[i] - b[i]);
	}
	rep(i, 1, n) a[i] = max(0ll, a[i] - k);
	rep(i, 1, n) if (a[i] != b[i])
	{
		cout << "NO";
		return;
	}
	cout << "YES";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
	{
		solo();
		cout << endl;
	}
	cout << "\n"
			 << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}