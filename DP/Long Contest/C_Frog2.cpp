#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define pb push_back
#define f first
#define s second
ll n, k;
vector<ll> height;
vector<ll> dp;

ll dyni(ll x)
{
  dp[1] = 0;
  if (x < 1)
    return INF;
  if (dp[x] != -1)
    return dp[x];
  if (x == 1)
    return dp[x] = 0;
  ll ans = INF;
  for (int i = 1; i <= k; i++)
  {
    if (x - i > 0)
      ans = min(ans, dyni(x - i) + abs(height[x] - height[x - i]));
  }

  return dp[x] = ans;
}
void muqtu()
{
  cin >> n >> k;
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