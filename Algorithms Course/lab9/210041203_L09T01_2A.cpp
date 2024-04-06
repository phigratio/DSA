#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll maxi = 1e6 + 1;
#define pb push_back
#define f first
#define s second

vector<ll> dp(maxi, -1);

ll dyni(vector<ll> &coins, ll x)
{
  dp[0] = 0;
  for (ll coin : coins)
  {
    for (ll i = coin; i <= x; i++)
    {
      if (dp[i - coin] != -1)
      {
        if (dp[i] == -1 || dp[i] > dp[i - coin] + 1)
        {
          dp[i] = dp[i - coin] + 1;
        }
      }
    }
  }
  return dp[x];
}

void muqtu()
{
  vector<ll> coins(maxi);
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  ll x;
  cin >> x;
  ll ans = dyni(coins, x);
  cout << ans << endl;
}

int main()
{
  faster;
  ll t = 1;
  while (t--)
  {
    muqtu();
  }
  return 0;
}
