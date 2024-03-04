#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

const ll inf = 1e18 + 1;
const ll maxN = 1005; // Assuming the maximum number of juices is 1000
const ll maxMask = 8;

ll dp[maxN][maxMask];

int main()
{
  ll n;
  cin >> n;

  vector<pair<ll, string>> juices(n);

  for (ll i = 0; i < n; i++)
  {
    cin >> juices[i].first >> juices[i].second;
  }

  for (ll i = 0; i <= n; i++)
  {
    for (ll j = 0; j < maxMask; j++)
    {
      dp[i][j] = inf;
    }
  }

  dp[0][0] = 0;

  for (ll i = 0; i < n; i++)
  {
    ll cost = juices[i].first;
    string s = juices[i].second;

    ll mask = 0;

    for (char c : s)
    {
      mask |= 1 << (c - 'A');
    }

    for (ll j = 0; j < maxMask; j++)
    {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j | mask] = min(dp[i + 1][j | mask], dp[i][j] + cost);
    }
  }

  ll ans = dp[n][7];

  if (ans == inf)
  {
    ans = -1;
  }

  cout << ans << endl;
  return 0;
}
