#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

const ll INF = 1e18;

ll dyni(ll m)
{
}

void muqtu()
{

  ll n, x;
  cin >> n >> x;
  vector<ll> coins(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  vector<ll> dp(x + 1, INF);

  dp[0] = 0;
  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (coins[j] <= i)
      {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }

  if (dp[x] != INF)
    cout << dp[x] << endl;
  else
  {
    cout << -1 << endl;
  }
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
