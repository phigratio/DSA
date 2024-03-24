#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll n;
vector<ll> height;
vector<ll> dp;
ll ans = INF;
ll dyni(ll x)
{
  if (x < 1)
    return INF;
  if (dp[x] != -1)
    return dp[x];
  if (x == 1)
    return dp[x] = 0;
  ll way1 = abs(height[x] - height[x - 1]);
  ll way2 = abs(height[x] - height[x - 2]);
  ans = min((dyni(x - 1) + way1), (dyni(x - 2) + way2));
  return dp[x] = ans;
}
void muqtu()
{
  cin >> n;
  height.resize(n + 1);
  dp.assign(n + 1, -1);
  for (int i = 1; i <= n; i++)
  {
    cin >> height[i];
  }

  cout << dyni(n) << endl;
  return;
}
int main()
{
  faster;
  ll t;
  t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}
