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
vector<ll> dp(1002, 0);
ll dyni(ll n, ll k)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  if (dp[n] != 0)
    return dp[n];

  ll ans = 0;
  for (int i = 1; i <= k; i++)
  {
    ans += dyni(n - i, k);
  }

  return dp[n] = ans;
}
void muqtu()
{
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 0)
      {
        dp[i] += dp[i - j];
      }
    }
  }

  cout << dp[n] << endl;
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