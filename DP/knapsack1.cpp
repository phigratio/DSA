#include <bits/stdc++.h>
using namespace std;
#define N 1e6 + 10;
#define ll long long
vector<ll> weight(102);
vector<ll> value(102);
vector<ll> dp[102][102];
ll ans(ll ind, ll amount)
{
  ans(ind - 1, amount);
}
int main()
{
  ll n, wt;
  cin >> n >> wt;
  for (int i = 0; i < n; i++)
  {
    cin >> weight[i] >> value[i];
  }

  cout << ans(n - 1, wt) << endl;
}