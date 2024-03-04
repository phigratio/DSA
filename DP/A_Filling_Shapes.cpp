#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> dp(1e6 + 30, -1);

ll dyni(ll x)
{
  if (x == 0)
    return 1;
  if (dp[x] != -1)
    return dp[x];

  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 2;

  for (ll i = 4; i <= x; i += 2)
  {
    dp[i] = dp[i - 2] * 2;
  }

  return dp[x];
}

int main()
{
  ll n;
  cin >> n;

  if (n % 2)
  {
    cout << 0 << endl;
    return 0;
  }
  else
    cout << dyni(n) << endl;

  return 0;
}
